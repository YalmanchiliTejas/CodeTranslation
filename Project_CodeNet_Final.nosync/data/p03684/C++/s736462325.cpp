#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#define MuhammedAly ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define popc(x) __builtin_popcount(x)
#define LLMX 1e18
#define NotinRange(n,m) i<0||i>=(n)||j<0||j>=(m)
#define mem(x,y) memset((x),(y),sizeof (x));
#define sz(a) (int)(a).size()
#define inFile(s) freopen((s),"r",stdin)
#define	outFile(s) freopen((s),"w",stdout)
#define biEdge(v, a, b) (v)[(a)].pb((b)), (v)[(b)].pb((a))
#define pi (2 * acos(0))
#define X real()
#define Y imag()
#define cross(a, b) ((conj(a) * (b)).Y)
#define dot(a, b) ((conj(a) * (b)).X)
#define vec(a,b) ((b) - (a))
#define ll long long
typedef long double ld;
typedef complex<double>point;
typedef tuple<int, int, int> line;
typedef pair<point, point>segment;
typedef vector<point>polygon;
const int N = 1e5 + 5, M = 100 + 5, OO = 0x3f3f3f3f, mod = 1e9 + 7, base = 131, mod2 = 1000136437, mod3 = 998244353;
const double EPS = 1e-9;
int n, rp[N], si[N];
ll ans;
vector<pair<int, pair<int, int>>>x, y;
map<int, vector<pair<int, int>>> mp;
int find(int u)
{
	return (rp[u] == u)? u : rp[u] = find(rp[u]);
}
bool join(int u, int v)
{
	u = find(u), v = find(v);
	if(u == v)
		return false;
	if(si[u] < si[v])
		swap(u, v);
	si[u] += si[v];
	rp[v] = u;
	return true;
}
int main()
{
    MuhammedAly
    cin >> n;
    fill(si, si + n + 1, 1);
    iota(rp, rp + n + 1, 0);
    x.resize(n);
    y.resize(n);
    for(int i = 0 ; i < n ; i++)
    {
    	cin >> x[i].first >> x[i].second.first;
    	y[i].first = x[i].second.first;
    	y[i].second.first = x[i].first;
    	x[i].second.second = y[i].second.second = i;
    }
    sort(all(x));
    sort(all(y));
    for(int i = 0 ; i < n - 1; i++)
    {
    	mp[x[i + 1].first - x[i].first].pb({x[i].second.second, x[i + 1].second.second});
    	mp[y[i + 1].first - y[i].first].pb({y[i].second.second, y[i + 1].second.second});
    }
    for(auto i : mp)
    {
    	for(auto j : i.second)
    		if(join(j.second, j.first))
    			ans += i.first;
    }
    cout << ans;
    return 0;
}