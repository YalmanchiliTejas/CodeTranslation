#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n, m;
vector<int> g[maxn];

int res;

set<int> act;

void dfs(int at) {
    act.insert(at);
    if (int(act.size())==n) res++;
    for (int to: g[at]) {
	if (act.count(to)) continue;
	dfs(to);
	act.erase(to);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
	int u,v; cin>>u>>v;
	--u; --v;
	g[u].push_back(v);
	g[v].push_back(u);
    }


    dfs(0);

    cout<<res<<endl;
    return 0;
}
