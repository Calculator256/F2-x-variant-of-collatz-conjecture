#include <vector>
#include <bit>
#include <algorithm>
#include <iostream>
using namespace std;

#define ll long long
#define ull unsigned ll
#define si short int
#define usi unsigned si
#define n 10
#define N 1<<n

ull CollatzRegrOp(ull pol){
  if(pol&1 == 0){
    return pol>>1; // dividing by x
  }
  return (pol<<1)^(pol^1); // multiplying by x+1 and adding 1
}

ull CollatzFastOp(ull pol){
  return ((pol^bit_floor(pol))<<1)^pol; // multiplying pol by x+1 and deleting the leading term, proven to be eqiuvelent(but faster bc it skips diviing) to the reguler F2[x] collatz operation
}

usi CollatzRegCollapseTime(ull pol){
  usi ans = 0;
  while(pol!=1){
    pol = CollatzRegrOp(pol);
    ans++;
  }
  return ans;
}

usi CollatzFastCollapseTime(ull pol){
  usi ans = 0;
  while(pol!=1){
    pol = CollatzFastOp(pol);
    ans++;
  }
  return ans;
}

int main(){
  vector<usi> CollatzFastCollapseTimeDp(N);
  CollatzFastCollapseTimeDp[1] = 0;
  for(ull i = 2; i < N; i*=2){
    for(ull j = i*2-1; j >= i; j-=2){
      CollatzFastCollapseTimeDp[j] = CollatzFastCollapseTimeDp[CollatzFastOp(j)]+1;
    }
  }
  int k = 1;
  cout << "max collapse time(fast operation) for length " << k << " is " << 0 << "\n";
  for(ull i = 2; i < N; i*=2){
    k++;
    usi maxTime = 0;
    for(ull j = i*2-1; j >= i; j-=2){
      maxTime = max(CollatzFastCollapseTimeDp[j], maxTime);
    }
    cout << "max collapse time(fast operation) for length " << k << " is " << maxTime << "\n";
  }
}
