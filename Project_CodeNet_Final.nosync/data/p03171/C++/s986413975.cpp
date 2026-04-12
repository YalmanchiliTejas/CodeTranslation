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
#define isize(x) (int)(x.size())
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define umap unordered_map


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	vi A = vi();
	rep(i, n){
		int x; cin >> x;
		A.pb(x);
	}
	vvll dp = vvll(n, vll(n, 0));
	// dp[i][j] = max X - Y for Ai,...,Aj
	// dp[i][j] = max(A[i] - dp[i+1][j], A[j] - dp[i][j-1])
	rep(i, n){
		dp[i][i] = A[i];
	}
	for(int c = 1; c < n; c++){
		for(int r = c-1; r >= 0; r--){
			dp[r][c] = max(A[r] - dp[r+1][c], A[c] - dp[r][c-1]);
		}
	}
	cout << dp[0][n-1];
}