#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const int maxn=1050;
ll dp[maxn][maxn];
ll Pow(ll x,ll n){
	ll ans=1,base=x%MOD;
	while(n){
		if(n&1) ans=ans*base%MOD;
		base=base*base%MOD;
		n>>=1;
	}
	return ans;
}
ll fact[maxn],inv[maxn];
void init(){
	fact[0]=1;
	for(int i = 1; i < maxn; ++i) fact[i]=fact[i-1]*i%MOD;
	inv[maxn-1]=Pow(fact[maxn-1],MOD-2);
	for(int i = maxn-2; i >= 0; --i) inv[i]=inv[i+1]*(i+1)%MOD;
}
int main(){
	init();
	int n,A,B,C,D;
	scanf("%d%d%d%d%d", &n,&A,&B,&C,&D);
	for(int i = 0; i <= B; ++i) dp[0][i]=1;
	for(int i = 1; i <= n; ++i){
		for(int j = A; j <= B; ++j){
			if(i==0) dp[i][j]=1;
			else{
				ll &u=dp[i][j];
				u=dp[i][j-1];
				for(int k = C; k <= D&&i-j*k>=0; ++k){
					u+=dp[i-j*k][j-1]*fact[n-i+j*k]%MOD*inv[j*k]%MOD*inv[n-i]%MOD*fact[j*k]%MOD*inv[k]%MOD*Pow(inv[j],k)%MOD;
					u%=MOD;
				}
			}
		}
	}
	cout << dp[n][B] << endl;
	return 0;
}
