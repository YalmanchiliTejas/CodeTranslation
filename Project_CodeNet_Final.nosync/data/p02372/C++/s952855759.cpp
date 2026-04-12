#include <bits/stdc++.h>
using namespace std;
#define dhoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
typedef long long ll;
#define SIZE 10005
vector< ll > dp[SIZE];
ll height[SIZE];
ll n;
vector< pair< ll , ll > > graph[SIZE];
ll dfs(ll u , ll i){
	if(dp[u][i] >= 0)
		return dp[u][i];
	dp[u][i] = graph[u][i].second;
	ll to = graph[u][i].first;
	int j = 0;
	for(auto it : graph[to]){
		if(it.first == u){
			j++;continue;}
		dp[u][i] = max(dp[u][i], dfs(to,j) + graph[u][i].second);
		j++;
	}
	return dp[u][i];
}
void solve(){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < (int)graph[i].size() ; j++)
		{
				if(dp[i][j] >= 0) continue;
				dp[i][j] = dfs(i , j); 
		}
	}
	for(int i = 0 ; i < n ; i++){
		height[i]  =0;
		for(int j = 0 ; j < (int)dp[i].size() ; j++){
			height[i] = max(height[i] , dp[i][j]);
		}	
	}
} 
int main(){
	dhoom;

	cin >> n;
	for(int i = 0 ; i < n - 1 ;i++){
		ll x , y , wt;
		cin >> x >> y >> wt;
		graph[x].push_back({y,wt});
		graph[y].push_back({x,wt});		
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < (int)graph[i].size() ; j++)
			dp[i].push_back(-1);
	}
	solve();
	for(int i = 0 ;i < n ;i++)
		cout << height[i] << endl;
    return 0;
}


