#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=998244353;
const int N=8010, M=205, LOG=14, NN=(1<<LOG);

ll n, m, k, u, v, x, y, t, a, b, ans;
ll F[N], I[N], A[NN], B[NN];
int rev[NN];
ll dp[M][N];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
ll nCr(ll n, ll r){
	if (r<0 || r>n) return 0;
	return F[n]*I[r]%mod*I[n-r]%mod;
}
inline void NTT(ll *A, bool inv){
	for (int i=1; i<NN; i++) if (rev[i]<i) swap(A[rev[i]], A[i]);
	for (int ln=1; ln<NN; ln<<=1){
		ll wn=powmod(3, mod/ln/2);
		if (inv) wn=powmod(wn, mod-2);
		for (int i=0; i<NN; i+=2*ln){
			ll w=1;
			for (int j=i; j<i+ln; j++){
				ll a=A[j], b=A[j+ln]*w;
				A[j]=(a+b)%mod;
				A[j+ln]=(a-b)%mod;
				w=w*wn%mod;
			}
		}
	}
	if (inv){
		ll invn=powmod(NN, mod-2);
		for (int i=0; i<NN; i++) A[i]=A[i]*invn%mod;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<N; i++) F[i]=F[i-1]*i%mod;
	I[N-1]=powmod(F[N-1], mod-2);
	for (int i=N-1; i; i--) I[i-1]=I[i]*i%mod;
	for (int i=1; i<NN; i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(LOG-1));
	
	cin>>n>>m;
	for (int j=0; j<=n; j++) B[j]=I[j+2];
	NTT(B, 0);
	dp[0][0]=1;
	for (int i=1; i<=m; i++){
		memset(A, 0, sizeof(A));
		for (int j=0; j<=n; j++) A[j]=dp[i-1][j]*I[j]%mod;
		NTT(A, 0);
		for (int j=0; j<NN; j++) A[j]=A[j]*B[j]%mod;
		NTT(A, 1);
		for (int j=1; j<=n; j++) dp[i][j]=A[j]*F[j+2]%mod;
		for (int j=1; j<=n; j++) dp[i][j]=(dp[i][j] - dp[i-1][j]*(j+1))%mod;
	}
	for (int i=0; i<=m; i++) for (int j=0; j<=n; j++)
		ans=(ans + nCr(m, i)*nCr(n, j)%mod*dp[i][j])%mod;
	if (ans<0) ans+=mod;
	cout<<ans<<"\n";
	
	return 0;
}
