
// Problem : A - Station and Bus
// Contest : AtCoder Beginner Contest 158
// URL : https://atcoder.jp/contests/abc158/tasks/abc158_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

/* ID: vqt
LANG: C++14
PROB: namenum
*/

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include<unistd.h>
// #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>

// defines
#define int long long
// typedef long long ll;
// #define double long double
#define vec vector
#define vi vector<int>
#define vvi vector<vector<int>>
#define p_q priority_queue
#define min_p_q priority_queue<int,vt <int>,greater <int>>
#define ii pair<int, int>
#define vii vector<ii>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)(x).size())
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
//#define UNI(x) (x).resize(unique((x).begin(), (x).end()) - (x).end());
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),(x))-c.begin())
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define RESET(X, y) memset(X, y, sizeof(X))
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

//Universal DEBUG: https://codeforces.com/blog/entry/68809
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/* To debug, just type: debug(x, y, z...). It requires C++ 11 or above.
It can work with: Primitive data types: bool, int, long long, float, ...; pair, string;
Collection types: std::vector, std::map, std::set, ...; Expressions
*/

//permanent constants
const long long INF64 = 1e18; const int INF32 = 1e9; const int BIG = (int)(1e9 + 239);
const int MOD = 1000000007; // (int)1e9+7; //998244353; const ll MOD2 = (ll)MOD * (ll)MOD;
const double PI = 2.0*acos(0.0); //acos(-1.0L);
const double EPS = static_cast<double>(1e-10);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dx[4] = {0, 1, 0, -1}; const int dy[4] = {1, 0, -1, 0};

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef vector<vector<int>> matrix;   //matrix Z(n, vector<LL>(n));

/*GRAPH:
	vector<vector<int>> dist; // ma tran dist giua cac dinh
    dist.assign(N, vector<int>(N, INF)); // Khoi tao ma tran dist bang INF
    Cach khac:
    vector<int> p;  vector<vector<int>> g; // khai bao
    p = vector<int>(n); // thay cho resize
	g = vector<vector<int>>(n); // // thay cho resize
*/
// Sort w Lambda Function: sort(begin(v), end(v), [] (int a, int b) { return a > b; });

//How to use "accumulate": https://www.fluentcpp.com/2017/10/17/stdaccumulate-your-knowledge-on-algorithms/
// array a: tinh XOR sum tu l den r:
#define XORsum(a, l, r) accumulate(a + l - 1, a + r, 0, [](int a, int b){  return a ^ b;  })

void FILEIO() {  freopen("in.txt", "r", stdin);  freopen("out.txt", "w", stdout); }
//void FILEIO() {  freopen("berries.in", "r", stdin);  freopen("berries.out", "w", stdout); }
//Tricks:
#define odd(x) ((x) & 1)
#define even(x) !((x) & 1)

int mostSignDigit(int n) { double k = log10(n); return (int)pow(10, k-floor(k));}
int numOfDigits(int n) {return (int)floor(log10(n)) + 1;}
bool isPowerOfTwo(int x) {return x && (!(x&(x-1)));} // first x is for the case x=0

bool allPositive(vector<int> &a) {return all_of(begin(a), end(a), [](int x){return x > 0;});} // are all of the elements positive?
bool anyPositive(vector<int> &a) {return any_of(begin(a), end(a), [](int x){return x > 0;});} // is there at least one positive element?
bool nonePositive(vector<int> &a) {return none_of(begin(a), end(a), [](int x){return x > 0;});} // are none of the elements positive?

//******************//

void solve() {
	string s; cin >> s;
	set<char> st;
	FOR(i, 0, 3) st.insert(s[i]);
	if(SZ(st)>=2) {cout << "Yes" << endl;}
	else cout << "No" << endl;
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie();
  // FILEIO();
//  auto beginProgram = chrono::steady_clock::now();

// preCalc();

// int t; cin >> t;
// FOR(i, 0, t)
  {
//	  cout << "Case #" << i+1 << ": " << solve() << endl;
	  solve();
  }

//  auto endProgram = chrono::steady_clock::now();
//  cout << chrono::duration_cast<chrono::milliseconds>(endProgram - beginProgram).count() << " ms" << endl;

  return 0;
}

