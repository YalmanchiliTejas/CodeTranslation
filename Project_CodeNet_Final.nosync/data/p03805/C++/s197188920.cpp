#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<string> vstr;
typedef pair<ll, ll> pll;
typedef vector<pll> vp;
typedef map<ll, ll> mll;
typedef map<string, ll> mstrll;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fir first
#define sec second
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep,)(__VA_ARGS__)
#define each(i, n) for(auto&& i: n)
#define out(x) cout << (x)
#define indent() cout << '\n'
#define print(x) cout << (x) << '\n'
#define debug(x) cerr << #x << ": " << (x) << '\n'
ll gcd(ll a, ll b){return b != 0 ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}
const ll INF = 1e16;
const ll MOD = 1e9 + 7;
ll a, b, c, n, m, x, y, z, w, h, ans, mx, mn;
string s, t;
vll dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
//vll dx = {-1, 0, 1, -1, 1, -1, 0, 1}, dy = {-1, -1, -1, 0, 0, 1, 1, 1};
string alphabet = "abcdefghijklmnopqrstuvwxyz";

bool graph[8][8], visited[8] = {true};

int dfs(ll v, ll n){
	bool all_visited = true;
    rep(i, n){
		if(visited[i] == false)
			all_visited = false;
	}
	if(all_visited){
		return 1;
	}
	ll ret = 0;
	rep(i, n){
		if(graph[v][i] == false) continue;
		if(visited[i]) continue;

		visited[i] = true;
		ret += dfs(i, n);
		visited[i] = false;
	}
	return ret;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(cin >> n >> m){
        mll cnt;
        rep(i, m){
            cin >> a >> b;
            graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
        }
        print(dfs(0, n));
    }
}
