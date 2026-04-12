#include<bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define ll long long
#define int long long

using namespace std ;


const int MAXN = 101 * 1001 , MOD = 1e9 + 7 ; 

vector<int> adj[MAXN] ; 

bool dp[MAXN][2] ; 

void dfs(int u , int p)
{
	dp[u][0] = 0 ;
    dp[u][1] = 1 ; 	
	set<int> s ;
	int c = 0 ; 
	for(auto v : adj[u])
	{
		if(v==p) continue ;
		dfs(v,u) ;
	    c++ ; 	
		dp[u][1] &= dp[v][0] ; 
		if(dp[v][0]) s.insert(v) ; 
	}
	for(auto v : adj[u])
	{
		if(v==p) continue ; 
		bool f = 0 ; 
		if(s.size()==c) f = 1 ;
		if(s.size()==c-1&&!s.count(v)) f = 1 ;
		dp[u][0] |= (dp[v][1] & f) ; 
	}

}

int32_t main()
{
	ios::sync_with_stdio(0) ; cin.tie(0) ; 
	int n  ; 
	cin >> n ; 
	for(int i = 1 ; i < n ; i ++ ) 
	{
		int x , y ; 
		cin >> x >> y ; 
		adj[x].pb(y) ; 
		adj[y].pb(x) ; 
	}
	dfs(1,0) ; 
	cout << (dp[1][0]?"Second":"First") << endl ; 

}