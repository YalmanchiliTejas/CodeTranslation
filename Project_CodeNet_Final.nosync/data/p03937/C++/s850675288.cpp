/*#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <array>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SORT(c) sort((c).begin(),(c).end())

typedef long long ll;
const ll INF = LLONG_MAX - 100;
const ll mod = 1e9 + 7;
const int MAX_N = 5e5 + 5;
int dx[] = { -1LL,0,1LL,0 }, dy[] = { 0,1LL,0,-1LL };
vector<ll> prime;

ll inv[MAX_N], fac[MAX_N];

template <class T = ll> T in() { T x; cin >> x; return (x); }
inline ll GCD(ll a, ll b) { ll c; while (b != 0) { c = a % b; a = b; b = c; }return a; }
inline ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
inline ll POW(ll a, ll b) { ll c = 1LL; while (b > 0) { if (b & 1LL) { c = a * c%mod; }a = a * a%mod; b >>= 1LL; }return c; }
inline void _nCr() { fac[0] = 1LL; for (int i = 1LL; i < MAX_N; i++) { fac[i] = fac[i - 1LL] * i%mod; }for (int i = 0; i < MAX_N; i++) { inv[i] = POW(fac[i], mod - 2); } }
inline ll nCr(ll n, ll r) { return (fac[n] * inv[r] % mod)*inv[n - r] % mod; }
inline void PRI(ll n) { bool a[n + 1LL]; for (int i = 0; i < n + 1LL; i++) { a[i] = 1LL; }for (int i = 2; i < n + 1LL; i++) { if (a[i]) { prime.pb(i); ll b = i; while (b <= n) { a[b] = 0; b += i; } } } }

typedef pair<int, pair<int, int>> edge;

class UnionFind {
private:
	vector<int> par;
public:
	UnionFind(int N) { par = vector<int>(N, -1LL); }
	int find(int x);
	ll size(int x);
	void unite(int x, int y);
	bool same(int x, int y);
};



class Kruskal {
private:
	UnionFind *uf;
	vector<edge> e;
public:
	vector<edge> mst;
	Kruskal(int N) { uf = new UnionFind(N); }
	void add(int x, int y, ll z);
	void run();
};



//----UnionFind-------------------------------
int UnionFind::find(int x) {
	if (par[x] < 0) return x;
	else return par[x] = find(par[x]);
}

ll UnionFind::size(int x) {
	return -par[find(x)];
}

void UnionFind::unite(int x, int y) {
	x = find(x);
	y = find(y);

	//大きい方に小さい方をくっ付ける
	if (size(x) < size(y)) swap(x, y);
	par[x] += par[y];
	par[y] = x;
}

bool UnionFind::same(int x, int y) {
	x = find(x);
	y = find(y);
	return x == y;
}



//----Kruskal-------------------------------
void Kruskal::add(int x, int y, ll z) {
	//x < y
	if (x > y) swap(x, y);
	e.push_back({ z,{x,y} });
}

void Kruskal::run() {
	sort(e.begin(), e.end());
	e.erase(unique(e.begin(), e.end()), e.end());
	for (auto x : e) {
		if (uf->same(x.second.first, x.second.second)) {
			continue;
		}
		else {
			mst.push_back(x);
			uf->unite(x.second.first, x.second.second);
		}
	}
}

void B() {cout << "Borys" << endl;}
void A() {cout << "Alice" << endl;}

signed main() {
	int h,w;
    cin >> h >> w;
    string a[h];
    REP (i,h) cin >> a[i];
    int hidari = 0,migi = 0;
    bool ok = true;
    int ccnt = 0;
    REP (i,h) {
        REP (j,w) {
            if (a[i][j] == '#') ccnt++;
        }
    }
    
    if (ccnt == h + w - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}