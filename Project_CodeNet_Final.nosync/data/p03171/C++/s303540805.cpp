#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
#define MOD 1000000007
#define INF 100000000000000 //INF - 1e14
#define vi vector<ll>
#define pb push_back
#define mpl map<ll,ll>
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vpll vector<pair<ll,ll> >
#define fer(i, a, n) for( ll i = a; i <= n; i++)
#define fdr(i, a, n) for( ll i = a; i >= n; i--)
#define invec(n,v) vi v(n); fer(i,0,n-1) cin >> v[i]
#define insvec(n,v) rin(n); vi v(n); fer(i,0,n-1) cin >> v[i]
#define MK2DV(v,row,col,val) vector<vector<ll> > v(row, vector<ll>(col,val))
#define matrix vector<vector<ll> >
#define printpartition cout << "-------------------------------------------------------------" << endl;
#define printmat(mat,row,col) cout << #mat << "::" << endl; fer(i,0,row-1)fer(j,0,col-1)cout << mat[i][j] << " \n"[j == col-1]; printpartition;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i : x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
template <typename T> inline void inp(T &any) {cin >> any;} template <typename T, typename... U>inline void inp(T &a, U &...b) {cin >> a; inp(b...);}
#define rin(args...) ll args; inp(args);
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#define matdeb(mat,row,col) printmat(mat,row,col);
#else
#define debug(x...)
#define matdeb(mat,row,col)
#endif
ll fast_pow(ll base, ll exp, ll M = MOD) { base = base % M; ll result = 1; while (exp > 0) { if (exp % 2 == 1) result = (result * base) % M; base = (base * base) % M; exp = exp / 2; } return result; }
ll modInverse(ll A, ll M = MOD) { return fast_pow(A, M - 2, M); } // only when M is prime
string yes = "Yes", no = "No";

const int N = 3000;
ll dp[2][N][N];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test_cases = 1;
	// cin >> test_cases;
	for (int test_case = 1; test_case <= test_cases; test_case++) {
		// cout << "Case #" << test_case << ": ";
		insvec(n, v);
		fer(i, 0, n - 1) {
			fer(j, 0, i) {
				if (i == j) {
					dp[0][i][i] = -v[i];
					dp[1][i][i] = v[i];
				}
				else {
					dp[0][i][j] = INF;
					dp[1][i][j] = -INF;
				}
			}
		}
		fer(d, 1, n - 1) {
			fer(i, 0, n - d - 1) {
				dp[0][i][i + d] = min(-v[i] + dp[1][i + 1][i + d], -v[i + d] + dp[1][i][i + d - 1]);
				dp[1][i][i + d] = max(v[i] + dp[0][i + 1][i + d], v[i + d] + dp[0][i][i + d - 1]);
			}
		}
		cout << dp[1][0][n - 1];
	}
	return 0;
}