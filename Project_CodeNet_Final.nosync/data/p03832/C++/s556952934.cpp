#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<tuple>
#include<bitset>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
const int MAX = 2000;
const int MOD = 1e+9+7;
ll fac[MAX], finv[MAX], inv[MAX];
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
long long COM(int n,int k){
    if(n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}
int main(){
	COMinit();
	int N,A,B,C,D;
	scan(N);scan(A);scan(B);scan(C);scan(D);
	ll dp[1001]={};
	dp[0]=1;
	for(int i=A;i<=B;i++){
		ll dpb[1001];
		fill(dpb,dpb+1001,0);
		rep(j,N+1){
			if(dp[j]==0) continue;
			ll way=1;
			for(int k=0;k<=N-j;k+=i){
				if(k==0||(C<=k/i&&k/i<=D)){
					dpb[j+k]+=dp[j]*way%MOD;
					dpb[j+k]%=MOD;
				}
				if(N-j-k<i) break;
				way=way*COM(N-j-k,i)%MOD*inv[k/i+1]%MOD;
			}
		}
		rep(j,N+1) dp[j]=dpb[j];
	}
	prin(dp[N]);
	return 0;
}
