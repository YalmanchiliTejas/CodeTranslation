#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
 UL N; scanf("%u",&N);
 UL A[100000]; rep(i,N) scanf("%u",&A[i]);
 UL Q; scanf("%u",&Q);
 rep(q,Q){
  UL k; scanf("%u",&k);
  UL l=0,r=N+1;
  while(l+1!=r){
   UL m=(l+r)>>1;
   if(A[m-1]<k) l=m;
   else r=m;
  }
  printf("%u\n",l);
 }
 return 0;
}


