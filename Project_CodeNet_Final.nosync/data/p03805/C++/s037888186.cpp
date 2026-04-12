# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
#include<limits.h>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<cstdio>
using namespace std;
typedef long long int ll;
const int N = 1000000;
const int mod = 1000000007;
const int INF = 1 << 30;
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
#define rep(i,n) for(ll i=(ll)0;i<(ll)n;++i)
#define vin(v,n) rep(i,n)cin>>v[i];
#define ALL(x) x.begin(),x.end()
#define pp pair<ll,ll>
#define sz size()
#define fi first
#define se second
#define pb push_back
string YN(bool b) { return(b ? "YES" : "NO"); }
string yn(bool b) { return(b ? "Yes" : "No"); }
ll n, m, a, b;
vector<ll>edge[8];
ll dfs(ll p, bitset<8>b2) {
	bitset<8>b = b2;
	b[p] = 1;
	bool fl = 1;
	rep(i, n)fl &= b[i];
	if(fl)return 1;
	ll ans = 0;
	rep(i, edge[p].sz) {
		if (!b[edge[p][i]]) ans += dfs(edge[p][i], b);
	}
	return ans;
}
int main() {
	cin >> n >> m;
	rep(i, m) {
		cin >> a >> b;
		edge[a - 1].pb(b - 1);
		edge[b - 1].pb(a - 1);
	}
	bitset <8> b = {};
	cout << dfs(0, b) << endl;
	return 0;
}