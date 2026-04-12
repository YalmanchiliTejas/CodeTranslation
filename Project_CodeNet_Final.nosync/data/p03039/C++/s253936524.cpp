// 解説に倣って
#include<bits/stdc++.h>
using namespace std;

int64_t modinv(int64_t a, int64_t m){
  int64_t b=m, u=1, v=0;
  while (b){
    int64_t t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  u%=m;
  if (u<0) u+=m;
  return u;
}

int64_t factorial(int64_t n, int64_t M){
  int64_t ans=1;
  while(n){
    ans=ans*n%M;
    n--;
  }
  return ans;
}

int64_t comb(int64_t n, int64_t r, int64_t M){
  return factorial(n,M)*modinv(factorial(n-r,M),M)%M*modinv(factorial(r,M),M)%M;
}

int64_t calc(int n, int m, int M){
  int64_t ans=0;
  for(int64_t d=1; d<n; d++){
    ans+=d*(n-d)*m*m;
    ans%=M;
  }
  return ans;
}

int main(){
  int M=1e9+7;
  int n,m,k;
  cin>> n >> m >> k;
  
  cout<< (calc(n,m,M)+calc(m,n,M)) * comb(n*m-2,k-2,M) % M <<endl;
}
// 考え方難しかった