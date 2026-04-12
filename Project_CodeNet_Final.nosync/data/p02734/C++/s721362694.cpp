#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"; return os;}
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const ll INF = 1e9+7;
const ll MOD = 998244353;


ll dp[3005][9005] = {};
int main(){
	ios_base::sync_with_stdio(false);
	ll N, S, ans=0;
	ll A[3005];

	cin >> N >> S;
	rep(i,N) cin >> A[i];

	rep(i,N){
		dp[i+1][A[i]] += i+1;
		rep(j,3005) dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
		rep(j,3005) dp[i+1][j+A[i]] = (dp[i+1][j+A[i]] + dp[i][j]) % MOD;
		if(S > A[i]) ans = (ans + dp[i][S-A[i]] * (N-i)) % MOD;
		if(S == A[i]) ans = (ans + (ll)(i+1) * (ll)(N-i)) % MOD;
	}

	// rep(k,3){
		// rep(i,N+1) cout << dp[i][S] << " "; cout << endl;
	// }
	//
	// rep(i,N) ans += dp[i+1][S][2];

	cout << ans << endl;

	return 0;
}