#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include<cmath>
#include<numeric>
#include<iterator>
#include<set>
#include<unordered_map>
#include<map>
#include<queue>
#include<cstring>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<functional>
#include<bitset>
#include<chrono>
#include<climits>
#include<assert.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>


#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define foru(i , a , b) for(int i = (int)(a) ; i < (int)(b) ; i++)
#define ford(i , a , b) for(int i = (int)(a) ; i >= (int)(b) ; i--)
#define ain(a , n) for(int i = 0 ; i < (int)n ; i++) cin >> a[i]
#define aout(a , n) for(int i = 0 ; i < (int)n ; i++) cout << a[i] << " "; cend
#define M 1000000007ll
#define mp make_pair
#define mt make_tuple
#define cend cout << "\n"
#define all(x) x.begin() , x.end()
#define aout2(a , n , m) for(ll i = 0 ; i < n ; i++){for(ll j = 0 ; j < m ; j++){cout << a[i][j] << " ";} cout << endl;}
#define ain2(a , n , m) for(ll i = 0 ; i < n ; i++){for(ll j = 0 ; j < m ; j++){cin >> a[i][j];}}
#define ff first
#define ss second
#define sz(a) ((int)(a).size())
#define mset(a , b) memset(a , b , sizeof(a))
#define pb push_back
#define endn '\n'
#ifndef ONLINE_JUDGE
#define dbg(a) cerr << #a << ": "; _print(a); cerr << endl;
#else
#define dbg(a) // No more TLEs
#endif

using namespace std;
using namespace std::chrono;
//using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <char> vch;
typedef vector <string> vs;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef pair <ll , ll> pll;
typedef vector <pair <ll , ll>> vpll;
typedef vector <pair <int, int>> vpi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


void _print(ll t){cerr<<t;}
void _print(int t){cerr<<t;}
void _print(string t){cerr<<t;}
void _print(char t){cerr<<t;}
void _print(ldb t){cerr<<t;}
void _print(double t){cerr<<t;}
void _print(ull t){cerr<<t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p){cerr<< "{";_print(p.ff);cerr<<",";_print(p.ss);cerr<<"}";}
template <class T> void _print(vector <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T> void _print(set <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
//void _print(ordered_set &v){cerr<<"[ ";for(int i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr<<"[ ";for(auto i: v){_print(i);cerr<<" ";}cerr << "]";}

/*----------------------------- # --- MATH ALGORITHMS --- # -----------------------------*/

template <class T> T gcd(T a , T b){ while(a != 0){T temp = a; a = b % a; b = temp;}return b;}
template <class T> T egcd(T a , T b , T &x , T &y){T gcd , xt , yt;if(a == 0){gcd = b;x = 0 , y = 1;}else {gcd = egcd(b % a , a , xt , yt);x = yt - (b/a)*xt; y = xt;}return gcd;}
template <class T> T expo(T base , T exp , T mod){T res = 1;base = base % mod;while (exp > 0){if (exp & 1)res = (res*base) % mod;exp = exp>>1;base = (base*base) % mod;}return res;}
template <class T> T modinv(T a , T mod){T x , y; egcd<T>(a , mod , x , y);while(x < 0) x += mod; while(x >= mod) x -= mod; return x;}
template <class T> T modinvfermat(T a , T mod){return expo<T>(a , mod - 2 , mod);}
template <class T> bool rev(T a , T b){return a > b;}
template <class T> ll maxpower(T a , T b){ll ans = 0;while(a > 0 && a % b == 0){ans++;a /= b;}return ans;}
template <class T> T mceil(T a, T b){if(a % b == 0) return a/b; else return a/b + 1;}
template <class T> T lcm(T a, T b){return (a*b)/gcd<T>(a, b);}
const ll infl = 1e18 + 5; const int inf = 1e9 + 5;

/*----------------------------- # --- MAIN CODE --- # -----------------------------*/

void test_case(){
	int n; cin >> n;
	if(n >= 30){
		cout << "Yes";
	}
	else cout << "No";
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif
	int _;
	_ = 1;
	// cin >> _;
	auto start = high_resolution_clock::now();
	cout << setprecision(20);
	while(_--){
		test_case();
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration.count()/1000.0 << endl;
#endif
	return 0;
}
