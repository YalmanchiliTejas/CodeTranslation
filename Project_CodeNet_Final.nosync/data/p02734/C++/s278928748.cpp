#include "bits/stdc++.h"
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 998244353;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

ll n,s;
Vi a;
ll dp[3001][3001];

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	std::cout<<std::fixed<<std::setprecision(30);
	cin>>n>>s;
	a.resize(n);
	rep(i,n){
		cin>>a[i];
	}
	rep(i,3001){
		rep(j,3001){
			dp[i][j]=0;
		}
	}
	rep(i,n){
		dp[i+1][a[i]] += i+1;
		dp[i+1][a[i]] %= Mod;
		rep(j,s+1){
			dp[i+1][j] += dp[i][j];
			dp[i+1][j] %= Mod;
			if(j+a[i]<=s){
				if(j==0)continue;
				dp[i+1][j+a[i]] += dp[i][j];
				dp[i+1][j+a[i]] %= Mod;
			}
		}
	}
	ll ans = 0;
	//ans = dp[n][s];
	rep(i,n){
		ans += dp[i+1][s];
		ans %= Mod;
	}
	print(ans);
	return 0;
}