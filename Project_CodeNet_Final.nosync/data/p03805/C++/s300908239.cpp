#include <bits/stdc++.h>
#define ll long long
#define INF 999999999
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 8;

vector<int> G[MAX_N];
int n;
ll ans;

void dfs(int v,set<int> S)
{
	S.insert(v);
	if(S.size() == n){
		ans++;
		return;
	}
	rep(i,G[v].size()){
		if(S.find(G[v][i]) == S.end()){
			dfs(G[v][i],S);
		}
	}
}

int main()
{
	int m,a,b;
	cin >> n >> m;
	rep(i,m){
		cin >> a >> b;
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
	}
	ans = 0;
	set<int> S;
	dfs(0,S);
	cout << ans << "\n";
}