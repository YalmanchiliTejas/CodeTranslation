#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<math.h>
#include<map>
#include <unordered_map> 
#include<vector>
#include<queue>
#include <bits/stdc++.h> 
#include<string>
#define ll long long int
#define N 3001
#define MOD 1e9+7
using namespace std;
string s1,s2;
template <typename T> void max_self(T &a, T b){
	if(b>=a){
		a = b;
	}
}
ll dp[N][N];
int vis[N][N];
ll a[N];
//itn dp[N];
ll solve(int i, int j){
	if(i==j)
		return a[i];
	if(i>j)
		return 0;

	if(vis[i][j])
		return dp[i][j];
	ll pos1a = a[i] + solve(i+1,j-1);
	ll pos1b = a[i] +solve(i+2,j);
 	ll pos2a = a[j] + solve(i+1,j-1);
 	ll pos2b = a[j] + solve(i,j-2);
 	ll pos1 = min(pos1a,pos1b);
 	ll pos2 = min(pos2a,pos2b);
 	ll ans = max(pos1,pos2);
 	dp[i][j] = ans;
 	vis[i][j] = 1;
 	return ans;
}
int main(){
	int n;
	cin>>n;
	ll sum = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	ll x = solve(1,n);
	cout<<2*x-sum;
	
}
