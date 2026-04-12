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
const int mod=1000000007;
const int MAXN=200010, LOG=20;

int n, m, k=inf, u, v, x, y, t, a, b, ans;
int A[MAXN];
int dp[MAXN];
string S;

inline void fix(int &x){
	if (x>=mod) x-=mod;
	if (x<0) x+=mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>S;
	for (int i=0; i<m; i++) if (S[i]=='R') S[i]='A'; // :(
	if (S[0]=='B'){
		for (int i=0; i<m; i++) S[i]='A'+'B'-S[i];
	}
	while (S.size()>1 && S.back()=='A') S.pop_back();
	m=S.size();
//	debug(S)
	if (m==1){
		dp[1]=1;
		for (int i=3; i<=n; i++){
			fix(dp[i]=dp[i-1]+dp[i-2]);
		}
		ans=n+1;
		for (int i=3; i<n; i++) ans=(ans + (n-i+1ll)*dp[i])%mod;
		fix(ans);
		cout<<ans<<"\n";
		
		return 0;
	}
	if (n&1) kill(0)
	for (int i=0, j=0; i<m; i=j){
		if (S[i]=='B') j++;
		else{
			while (S[j]=='A' && j<m) j++;
			if (i==0 || (j-i)%2==1) k=min(k, j-i);
		}
	}
//	debug(k)
	k>>=1;
	n>>=1;
//	debug2(n, k)
	dp[0]=1;
	dp[1]=1+(k>=1);
	for (int i=2; i<=n; i++){
		fix(dp[i]=2*dp[i-1]-(k>=i-1)+(k>=i));
		if (i>=k+2) fix(dp[i]-=dp[i-k-2]);
	}
//	debug(dp[1])
//	debug(dp[2])
//	debug(dp[3])
	
	for (int i=0; i+2<=n; i++) if (n-i-2<=k) ans=(ans + (n-i-1ll)*dp[i])%mod;
	if (n-1<=k) fix(ans+=n);
	fix(ans*=2);
	fix(ans);
	cout<<ans<<"\n";
	
	return 0;
}
/*
12 5
AAAAB

6 5
RRRRB

6 5
RRBRB


*/