#include <bits/stdc++.h>
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end() 
#define max_pqueue priority_queue< long long >
#define min_pqueue priority_queue< long long , vector<long long> , greater< long long >>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vl vector<long long>
#define vll vector<pair<long long, long long>>
#define FF first
#define SS second

//~ setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//~ setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//~ setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//~ cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

#ifndef LOCAL_MACHINE
#define cerr if (false) cerr
#endif

using namespace std;

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
void __print(const T &x) {int f = 0; cerr << '{'; for (auto i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
template<typename T>
void _printA(T *t, long long sz) { cout<<" { "; for (long long i=0; i<sz; i++) cout<<"["<<i<<"] = "<< t[i]<<endl; cout<<" } \n";}
#ifdef LOCAL_MACHINE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define debugA(x, y) cerr << "[" << #x << "] = "; _printA(x, y)
#else
#define debug(x...)
#define debugA(x, y)
#endif

const ll _MOD =   998244353LL;

ll mod(ll a, ll m=_MOD) {
	return (a + m) % m;
}

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll modinv(ll a, ll m=_MOD) {
	ll x, y;
	gcd(a, m, x, y);
	x = (x % m + m) % m;
    return x;
}

/* ------------------------------------------------------------------ */

ll A[(int)1e5+5];
ll dp[(int)3e3+5][(int)3e3+5];
bool setdp[(int)3e3+5][(int)3e3+5];
// 0 -> Taro (start)
// 1 -> Jiro

ll recur(int s, int e) {
	if (s==e)
		return A[s];
	if (s - e + 1 == 2)
		return max(A[s], A[e]) - min(A[s], A[e]);
	if (setdp[s][e])
		return dp[s][e];
	ll a = recur(s+1, e);
	ll b = recur(s, e-1);
	setdp[s][e] = 1;
	return dp[s][e] = max(-a + A[s], -b + A[e]);
}

void solve() {
	ll N;
	cin>>N;
	for (int i=0; i<N; i++)
		cin>>A[i];
	memset(setdp, 0, sizeof(setdp));
	cout<<recur(0, N-1)<<endl;
}

int main() {
#ifdef LOCAL_MACHINE
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
freopen("in", "r", stdin);
#pragma GCC diagnostic pop
#endif
	
	fast_io;
	ll T;
	T = 1;
	//~ cin>>T;
	for (ll t=0; t<T; t++) {
		solve();
	}
}	









