#include <bits/stdc++.h>
const long long MOD = 1000000007;
const int INF = INT_MAX / 2;
const long double PI = 3.1415926;
#define FOR(i, r, n) for(int i=(ll)(r); i<(ll)(n); i++) 
#define REP(i, n) FOR(i, (0), n)
#define ALL(r) r.begin(), r.end()
#define ll long long int
using namespace std;
string s;
vector<ll> v;
vector<pair<ll, ll>> vp;
vector<vector<ll>> vv(110, vector<ll>(50, 0));
vector<tuple<ll, ll, ll>> vt;
set<ll> st;
map<char, ll> mp;

typedef int Weight;
struct Edge
{
	int from, to; Weight cost;
	bool operator < (const Edge& e) const { return cost < e.cost; }
	bool operator > (const Edge& e) const { return cost > e.cost; }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
void add_edge(Graph &g, int from, int to, Weight cost)
{
	g[from].push_back(Edge{ from, to, cost });
}

typedef pair<Weight, Edge> P;

int main()
{
	int n;
	cin >> n;
	cout << (n * 800 - (n / 15) * 200) << endl;
}