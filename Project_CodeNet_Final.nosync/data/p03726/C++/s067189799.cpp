
// In the name of God
#include <bits/stdc++.h>

using namespace std;
#define Size(x) ((int)(x).size())
#define pb push_back
#define LD_OUT setprecision(12) << fixed
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const int INF = 1e9 + 10;
const int MN = 1e5 + 10;

int n ;
bool dp1[MN] , dp0[MN];
vector<int>adj[MN];

void dfs(int s,int pr)
{
	int C = 0;
	for(auto v:adj[s]) if(v!=pr){
		dfs(v , s);
		if(dp0[v]) ++C;	
	}
	for(auto v:adj[s]) if(v != pr){
		C -= dp0[v];
		if(dp1[v] && C == Size(adj[s])-2+(pr == -1)) dp0[s] = true;
		C += dp0[v];
	}
	if(C == Size(adj[s])-1) dp1[s] = true;
}

int main()
{
	ios_base :: sync_with_stdio(false) ,cin.tie(0) , cout.tie(0);
	cin >> n;
	for(int i=0;i<n-1;++i){
		int a,b;cin>>a>>b;--a,--b;
		adj[a].pb(b) , adj[b].pb(a);
	}
	dfs(0 , -1);
	if(dp0[0]) cout << "Second\n";
	else cout << "First\n";
	return 0;
}
