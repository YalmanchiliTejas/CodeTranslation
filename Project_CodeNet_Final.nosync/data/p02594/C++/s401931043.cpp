
// Problem : A - Air Conditioner
// Contest : AtCoder - AtCoder Beginner Contest 174
// URL : https://atcoder.jp/contests/abc174/tasks/abc174_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/* ID: vqt
LANG: C++14
PROB: namenum
*/

#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include<unistd.h>
using namespace std;

//for PDBS use only:
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
// #define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>

// defines
#define int long long
// #define double long double
#define vec vector
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define F first
#define S second
#define MP make_pair
#define vii vector<ii>
#define PQ priority_queue
#define minPQ priority_queue<int,vt <int>,greater <int>>
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define ER equal_range
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)(x).size())
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define UNI(c) c.resize(distance(c.begin(),unique(c.begin(),c.end())));
#define SORT_UNI(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define POS(c,x) (lower_bound(c.begin(),c.end(),(x))-c.begin())
#define max(a, b) ((a)<(b)? b : a)
#define min(a, b) ((a)<(b)? a : b)
#define setmin(a, b) a = min(a, b)
#define setmax(a, b) a = max(a, b)
#define MINMAX(x) minmax_element(begin(x), end(x))

//permanent constants
const long long INF64 = 1e18; const int INF32 = 1e9;
const double EPS = static_cast<double>(1e-10);
const double PI = 2.0*acos(0.0); //acos(-1.0L);
const int MOD = (int)1e9+7; //998244353
ll powMod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll invMod(ll a) {ll b=MOD,u=1,v=0;while(b){ll t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v);} return (MOD + u) % MOD;}
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//Tricks:
// Sort w Lambda Function: sort(begin(v), end(v), [] (int a, int b) { return a > b; });
// Sort vector cua bo ba so: struct MyStr {int a, b, c;}; vector<MyStr> v; ...fill v...
// sort(all(v), [](MyStr &A, MyStr &B) { return tie(A.a, A.b, A.c) < tie(B.a, B.b, B.c); });
#define odd(x) ((x) & 1)
#define even(x) !((x) & 1)
// vec - vector, p(x) - predicate so that p(x) = true for all elements of some prefix of vector
// vec and false on all others. To find the first place where p(x) doesn't hold one can simply use: 
#define FIRST_FAIL(vec, p) partition_point(ALL(vec), p) - vec.begin()
// partition_point(begin, end, p) returns the first ITERATOR it that p(*it) = false
#define isIn(vec, key) binary_search(ALL(vec), key)
#define toBool(num) !!(num)
#define bin(N, num) cerr << bitset<N>(num) << "\n"
// vector a: tinh XOR sum tu l den r:
#define XORsum(a, l, r) accumulate(a.begin()+l-1, a.begin()+r, 0, [](int x, int y){ return x^y; })
// BASIC STRING: just like vector but allows to use a few string member functions/operators: operator+ and operator+=.:
/*  int n;    basic_string<int> a;
    cin >> n; FOR(i, 0, n) { int x;   cin >> x; a += x; }
    a += a; a = a.substr(n/2, n);
    cout << (a + a).find({1, 2, 1}) << '\n';
*/
// count(a.begin(), a.end(), val) - count how many val in an array a
vector<int> prefixSum(vector<int> &a) {vi b; std::partial_sum(a.begin(), a.end(), b.begin()); return b;} 

int mostSignDigit(int n) { double k = log10(n); return (int)pow(10, k-floor(k));}
int numOfDigits(int n) {return (int)floor(log10(n)) + 1;}
bool isPowerOfTwo(int x) {return x && (!(x&(x-1)));} // first x is for the case x=0

bool allPositive(vector<int> &a) {return all_of(begin(a), end(a), [](int x){return x > 0;});} // are all of the elements positive?
// CHECK there is all numbers in array is positive: bool ok=true; for(auto z: a) ok &= (z>0);
bool anyPositive(vector<int> &a) {return any_of(begin(a), end(a), [](int x){return x > 0;});} // is there at least one positive element?
bool nonePositive(vector<int> &a) {return none_of(begin(a), end(a), [](int x){return x > 0;});} // are none of the elements positive?

void FILEIO() {  freopen("in.txt", "r", stdin);  freopen("out.txt", "w", stdout); } 
//void FILEIO() {  freopen("berries.in", "r", stdin);  freopen("berries.out", "w", stdout); } // USACO

/****************** DEBUG *******************/
//Universal DEBUG: https://codeforces.com/blog/entry/68809
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
// void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "T" : "F");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
//********************** Codes go here *********************/


void solve() {
	int x; cin >> x;
	if(x>=30) cout << "Yes" << endl;
	else cout << "No" << endl;
}


signed main() {
  ios_base::sync_with_stdio(false); cin.tie();
  // FILEIO();
//  auto beginProgram = chrono::steady_clock::now();

// preCalc(); // any 1-time precalculation need to do before many test cases?

// int t; cin >> t; FORE(i, 1, t)
  {
	  // cout << "Case #" << i << ": "; // Google CodeJam style
	  solve();
  }

//  auto endProgram = chrono::steady_clock::now();
//  cerr << chrono::duration_cast<chrono::milliseconds>(endProgram - beginProgram).count() << " ms" << endl;
  return 0;
}