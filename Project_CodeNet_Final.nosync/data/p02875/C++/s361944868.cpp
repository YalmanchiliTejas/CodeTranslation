#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int nMax=1e7+1, MOD=998244353;
ULL inv[nMax], Fact[nMax], invF[nMax];
ULL pw(ULL a, ULL n){ ULL b=1; while(n){ if(n&1){ b=(b*a)%MOD; } a=(a*a)%MOD; n>>=1; } return b; }
ULL Comb(int n, int r){ return (((Fact[n]*invF[r])%MOD)*invF[n-r])%MOD; }

int main(){
ULL N, ans, d=0; cin >> N;
inv[1]=Fact[0]=Fact[1]=invF[0]=invF[1]=1;
for(int i=2; i<nMax; i++){ 
  inv[i]=((MOD-MOD/i)*inv[MOD%i])%MOD;
  Fact[i]=(Fact[i-1]*i)%MOD; invF[i]=(invF[i-1]*inv[i])%MOD;
}
for(int i=N/2+1; i<=N; i++){ d=(d+(Comb(N, i)*pw(2, N-i))%MOD)%MOD; }
d=(2*d)%MOD; ans=(pw(3, N)+MOD-d)%MOD;
cout << ans << "\n";
}