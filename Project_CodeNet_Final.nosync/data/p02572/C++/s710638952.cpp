#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(int)(n); i++)
typedef unsigned long long ULL;
const int MOD=1e9+7;
ULL pw(ULL a, ULL n){ ULL b=1; while(n){ if(n&1){ b=(b*a)%MOD; } a=(a*a)%MOD; n>>=1; } return b; }

int main(){
int N; cin >> N; ULL ans=0, S=0, T=0, A[N]; 
REP(i, N){ cin >> A[i]; S=(S+A[i])%MOD; T=(T+(A[i]*A[i])%MOD)%MOD; }
ans=((S*S)%MOD+(MOD-T))%MOD; ans=(ans*pw(2, MOD-2))%MOD;
cout << ans << "\n";
}