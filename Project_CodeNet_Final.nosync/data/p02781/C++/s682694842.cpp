#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<vector<vector<ll> > > vvvl;
ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

ll solve(string s,int k){
    ll n = s.size();
    vvvl dp(110,vvl(2,vl(5,0))); //dp[桁数][ある数字未満か][0でない個数]
    dp[0][0][0] = 1;

    for ( int i = 0; i < n; ++i ){
		const int D = s[i] - '0'; //左から数えた桁数

		for ( int j = 0; j < 2; ++j ){
			for ( int k = 0; k < 4; ++k ){
				for ( int d = 0; d <= ( j ? 9 : D ); ++d ){
					dp[ i + 1 ][ j || ( d < D ) ][ k + (d != 0) ] += dp[i][j][k];
				}
			}
		}
	}
    ll res = 0;
    rep(i, 2) {  
        res += dp[n][i][k];
    }
	return res;
}
signed main()
{   
    gearup;
    string n;
    int k; cin >> n >> k;
    cout << solve(n,k) << endl;
}
