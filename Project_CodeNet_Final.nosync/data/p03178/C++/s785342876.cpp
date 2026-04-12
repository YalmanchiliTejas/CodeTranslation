/*
 * zyrch - Rupanshu Yadav
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

#define forn(i,a,b) for (int i = (a); i < ll(b); ++i)
#define fo(i,a) forn(i,0,ll(a))
#define rforn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ro(i,a) rforn(i,0,a)
#define trav(a,x) for (auto& a: x)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define rsz resize
#define ins insert

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
ll mod = 1000000007;
inline int fast_expo(int base,int power,int modulo=mod){
    base%=modulo;
    if (base<0) base+=modulo;
    ll x=base,cnt=power,ans=1;
    while(cnt){
        if (cnt&1) ans=(ans*x)%modulo;
        x=(x*x)%modulo;
        cnt>>=1;
    }
    return ans;
}

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

const int INF = (int)1e9;
//=========================CODE STARTS HERE=============================//

void add_self (ll &a, ll b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

ll d;
string k;

ll dp[10005][105][2];

int main() {

	fast_cin();

	//~ str k;
	cin >> k;
	
	//~ ll d;
	cin >> d;
	
	ll digits = k.length();
	
	//~ for (int i = 1; i < digits; ++i) {
		for (int j = 0; j < d; ++j) {
			dp[0][j][1] = dp[0][j][0] = 0;
		}
	//~ }
	
	
	for (int i = 0; i < k[0] - '0'; ++i) {
		dp[0][i % d][0] += 1;
		dp[0][i % d][1] += 0;
	}
	
	dp[0][(k[0] - '0') % d][1] += 1;
	dp[0][(k[0] - '0') % d][0] += 0;
	
	for (int i = 1; i < digits; ++i) {
		for (int j = 0; j < d; ++j) {
			dp[i][j][1] = dp[i][j][0] = 0;
		}
	}
	
	for (int i = 0; i < digits - 1; ++i) {
		for (int j = 0; j < d; ++j) {
			
			for (int o = 0; o < 10; ++o) {
				add_self(dp[i + 1][(j + o) % d][0], dp[i][j][0]);
			}
			
			for (int o = 0; o < k[i + 1] - '0'; ++o) {
				add_self(dp[i + 1][(j + o) % d][0], dp[i][j][1]);
			}
			add_self(dp[i + 1][(k[i + 1] - '0' + j) % d][1], dp[i][j][1]);
			
		}
	}
	
	ll ans = (dp[digits - 1][0][0] + dp[digits - 1][0][1]) % mod - 1;
	
	if (ans == -1) {
		ans += mod;
	}
	
	cout << ans << endl;
	
    return 0;
}
