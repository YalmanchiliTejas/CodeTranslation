#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using msi = map<string, int>;
using mii = map<int, int>;
using psi = pair<string, int>;
using pii = pair<int, int>;
using vlai = valarray<int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 1E9
#define EPS 1E-9
#define MOD (1E9+7)
#define PI 3.1415926535897932384

std::ostream &operator<<(std::ostream &out, const vector<int> &tgt)
{
	string s;
	for (int i = 0; i<tgt.size(); i++) {
		s += (to_string(tgt[i]) + ((i != tgt.size() - 1) ? " " : ""));
	}
	out << s;
	return out;
}

struct edge {
	vi to;
};

int ans = 0,n;
vector<edge> g;
vector<bool> b;

void dfs(int node, int num) {
	if (num==n) {
		ans++;
		return;
	}
	b[node] = true;
	rep(i, g[node].to.size()) {
		if (!b[g[node].to[i]]) {
			dfs(g[node].to[i], num + 1);
		}
	}
	b[node] = false;
}

int main() {
	int m,in,inn;
	cin >> n >> m;
	g.resize(n);
	b.resize(n);
	rep(i, n) {
		b[i] = false;
	}
	rep(i, m) {
		cin >> in >> inn;
		g[in - 1].to.push_back(inn - 1);
		g[inn - 1].to.push_back(in - 1);
	}
	dfs(0, 1);
	cout << ans<<endl;
}
