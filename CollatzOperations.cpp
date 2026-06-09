#include <bit>
using namespace std;

#define ll long long
#define ull unsigned ll
#define si short int
#define usi unsigned si

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
}

usi CollatzFastCollapseTime(ull pol){
  usi ans = 0;
  while(pol!=1){
    pol = CollatzFastOp(pol);
    ans++;
  }
}
