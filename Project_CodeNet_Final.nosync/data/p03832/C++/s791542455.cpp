#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n)repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
typedef pair<int,int> P;
typedef pair<int, P> PP;
#define all(v) v.begin(),v.end()
#define fi first
#define se second
const int inf = 1e9;
int mod = 1e9+7;

int dp[2000][2000], fac[2000], inv[2000];
int Pow(int x, int k){
	int res = 1;
	while(k > 0){
		if(k&1)res = (x*res)%mod;
		x = (x*x)%mod;
		k >>= 1;
	}
	return res;
}
void Factrial(int n){
	fac[0] = inv[0] = 1;
	rrep(i,n){
		fac[i] = (fac[i-1]*i)%mod;
		inv[i] = Pow(fac[i], mod-2);
	}
}
int perm(int n, int k){
	return (fac[n]*inv[n-k])%mod;
}

signed main(){
	int n, a, b, c, d;
	scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
	Factrial(1002);
	
	dp[a-1][0] = 1;
	repi(i,a,b+1)rep(j,n+1){
		dp[i][j] = dp[i-1][j];
		repi(k,c,d+1){
			if(j-i*k < 0)break;
			int tmp1 = (dp[i-1][j-i*k]*perm(n-j+i*k,i*k))%mod;
			int tmp2 = (Pow(inv[i], k)*inv[k])%mod;
			dp[i][j] += (tmp1*tmp2)%mod;
			dp[i][j] %= mod;
		}
	}
	printf("%lld\n",dp[b][n]);
	return 0;
}
