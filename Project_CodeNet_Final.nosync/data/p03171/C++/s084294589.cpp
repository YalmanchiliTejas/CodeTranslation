#include<iostream>
#include<bits/stdc++.h>
#define mod 1000000007
#define int long long
#define pii pair<int,int>
#define pb(x) push_back(x)
#define lbound lower_bound
#define ubound upper_bound
#define gcd(a,b) __gcd(a,b)
#define all(v) v.begin(),v.end()
#define bits(x) __builtin_popcountll(x)
#define heap_min priority_queue<int,vector<int>,greater<int>>
#define heap_max priority_queue<int>
#define printv(v) for(auto p : v) cout << p << " ";
#define printa(a,n) for(int i = 0 ; i < n ; i++) cout << a[i] << " ";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int a[3001];
int dp[3001][3001];

int solve(int i,int j){
	if(i>j){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	return dp[i][j] = max(a[i]+min(solve(i+2,j),solve(i+1,j-1)),a[j]+min(solve(i,j-2),solve(i+1,j-1)));
	
}
int32_t main()
{
	int n,k;
	cin >> n;
	int tot = 0;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		tot+=a[i];
	}
	memset(dp,-1,sizeof(dp));
	k = solve(0,n-1);
	cout << k-(tot-k);
}
