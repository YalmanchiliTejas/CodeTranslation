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

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

struct robot {
	ll x, d;
};

bool robot_sort(robot &a, robot &b) {
	return a.x < b.x;
}

void solve() {
	//~ ll N, P;
	//~ string S;
	//~ cin>>N>>P;
	//~ cin>>S;
	//~ vector<ll> mulP;
	//~ for (ll i=1; i*P<=2*(ll)1e5; i++) {
		//~ mulP.pb(i*P);
	//~ }
	
	string S;
	cin>>S;
	
	int cntA = 0, cntB = 0;
	for (char c : S) {
		if (c == 'A') cntA++;
		if (c == 'B') cntB++;
	}
	
	if (cntA > 0 and cntB > 0) {
		cout<<"Yes\n";
		return;
	}
	
	cout<<"No\n";
	
	//~ ll N;
	//~ cin>>N;
	//~ vector<robot> r;
	//~ for (int i=0; i<N; i++) {
		//~ ll x, d;
		//~ cin>>x>>d;
		//~ r.pb({x, d});
	//~ }
	
	//~ sort(r.begin(), r.end(), robot_sort);
	//~ vector<ll> grp;
	//~ ll grp_size = 1;
	//~ ll max_d = -1;
	//~ for (int i=0; i<(int)r.size(); i++) {
		//~ max_d = max(max_d, r[i].d);
		//~ if (i<(int)r.size()-1 and r[i+1].x < r[i].x + max_d) {
				//~ grp_size++;
			//~ }
			//~ else {
				//~ grp.pb(grp_size);
				//~ grp_size = 1;
				//~ max_d = -1;
			//~ }
	//~ }
	
	//~ debug(grp);
	//~ ll ans = 1;
	//~ for (ll g : grp) {
		//~ ans = mod(ans * mod(g + 1));
	//~ }
	
	//~ cout<<mod(ans)<<endl;
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









