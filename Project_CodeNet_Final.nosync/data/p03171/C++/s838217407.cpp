#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
 
#include<bits/stdc++.h>
 
using namespace std;
#define ll long long 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ull unsigned long long
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ff first
#define ss second
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0); 
#define nl "\n"
#define sz(a) (int)(a).size() 
#define all(a) (a).begin(),(a).end()
#define fl(a,x) memset(a,x,sizeof(a));
#define pt(a,x) cout << get<x>(a) << " " ;  
#define mt make_tuple 
#define vec vector
 
#define int long long 
 
const int mod = (int) 1e9 + 7 ;
const int MOD = (int) 998244353 ;
const int INF = (int) 1e18 ;
 
typedef vector<int> vii;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef vector<vector<int> > vv;
 
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

const int N = 3e3 + 5; 
int dp[N][N]; 

void solve(int test) {
	int n; cin >> n ;
	int a[n+1]; rep(i,1,n+1) cin >> a[i] ;

	for(int i = n ; i > 0 ; --i ) {
		for(int j = i ; j <= n ; ++j ) {
			if(i == j ) dp[i][j] = a[i] ;
			else dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]) ;
		}
	}

	cout << dp[1][n] ; 
}

int32_t main() {
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif   

    fast;
	int t=1;
	// cin>>t;
	rep(i,1,t+1) {
		solve(i) ;
	}
 
	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}