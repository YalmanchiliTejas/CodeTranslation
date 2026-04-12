#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 1010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, c, d, ans;
ll F[MAXN], I[MAXN];
ll dp[MAXN][MAXN];
ll C[MAXN][MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

ll count(ll n, ll k){ // n*k nafar   k group
	ll res=F[n*k]*powmod(I[n], k)%mod;
	return res*I[k]%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	
	for (int i=0; i<MAXN; i++){
		C[i][0]=C[i][i]=1;
		for (int j=1; j<i; j++) C[i][j]=(C[i-1][j] + C[i-1][j-1])%mod;
	}
	cin>>n>>a>>b>>c>>d;
	
	for (int i=0; i<MAXN; i++) dp[0][i]=1;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=b; j++){
			dp[i][j]=dp[i][j-1];
			if (a<=j) for (int t=c; t<=d && t*j<=i; t++) dp[i][j]=(dp[i][j] + dp[i-t*j][j-1]*C[i][t*j]%mod*count(j, t))%mod;
		}
	}
	
	ans=dp[n][b]%mod;
	if (ans<0) ans+=mod;
	cout<<ans<<'\n';
	
	return 0;
}
