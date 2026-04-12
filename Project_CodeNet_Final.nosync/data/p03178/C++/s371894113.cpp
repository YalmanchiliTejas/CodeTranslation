// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const int NINF = -1*INF;
const long long LLINF = 1ll << 60;
const long long LLNINF = -1*LLINF;

template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x) os << y << " ";
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
	return os << "[ " << p.first << ", " << p.second << "]" ;
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<ld> vld;
typedef vector<pi> vpi;
typedef vector<vector<int>> vvi;
typedef vector<vll> vvll;
typedef vector<vd> vvd;
typedef vector<vld> vvld;
 
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define revAll(x) x.rbegin(), x.rend()
#define gcd(a, b) __gcd(a, b)
#define popcount(x) __builtin_popcount(x)
#define isize(x) (int)(x.size())
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define umap unordered_map

const ll MOD = 1e9 + 7;

void madd(ll& a, ll b){
	a += b;
	if (a >= MOD) a -= MOD;
}

void msub(ll& a, ll b){
	a -= b;
	if (a < 0) a += MOD;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string K; cin >> K;
	int D; cin >> D;
	vi lim = vi();
	for(const auto& c : K){
		lim.pb((int)(c - '0'));
	}
	int n = isize(lim);
	ll dp[n+1][2][D];
	rep(i,n+1)rep(j, 2)rep(k, D) dp[i][j][k] = 0;
	dp[0][1][0] = 1;

	for(int i = 0; i < n; i++){
		for(int tight = 0; tight <= 1; tight++){
			for(int ds = 0; ds < D; ds++){
				int md = tight ? lim[i] : 9;
				for(int d = 0; d <= md; d++){
					int nt = (tight and lim[i] == d) ? 1 : 0;
					int nds = (d + ds) % D;
					madd(dp[i+1][nt][nds], dp[i][tight][ds]);
				}
			}
		}
	}
	ll ans = 0;
	madd(ans, dp[n][0][0]);
	madd(ans, dp[n][1][0]);
	msub(ans, 1);
	cout << ans;	
}