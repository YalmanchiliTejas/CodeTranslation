#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=12;
int N, M;
vector<int> g[MAX_N];
ll dp[MAX_N][1<<MAX_N];

void add_edge(int from, int to)
{
	g[from].push_back(to);
	g[to].push_back(from);
}

ll go(int at, int f)
{
	if(f == ((1<<N)-1)) return 1;
	ll& res = dp[at][f];
	if(res != -1) return res;
	res = 0;
	for(int i=0;i<(int)g[at].size();++i){
		int to = g[at][i];
		if(!(f>>to&1)) res+=go(to,f|(1<<to));
	}
	return res;
}

void solve()
{
	memset(dp,-1,sizeof(dp));
	ll res = go(0, 1);
	cout << res << '\n';
}

int main()
{
	cin >> N >> M;
	int a, b;
	for(int i=0;i<M;++i){
		cin >> a >> b;
		add_edge(a-1,b-1);
	}
	solve();
	return 0;
}