#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//Micro Futures scalping to get my tendies
vector<int> adj[200200];
int dp[200200];
int arr[200200]; int h[200200];
int sum = 0;
int dfs(int root){ 
	int sum = 0;
	for(auto xx : adj[root]){
		sum += dfs(xx);
	}
	return sum+arr[root-1];
}
int main(){
	ll x; cin>>x;
	if(x >= 30) cout<<"Yes"<<"\n";
	else cout<<"No\n";
}