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
#define N 3007
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

int main(){
	int n;
	cin>>n;
	ll sum = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	//ll x = solve(1,n);
	for(int gap =0;gap<n;gap++){
		for(int i=0;i<n;i++){
		    int j = i+gap;
			if(j >= n)
				continue;
			if(gap==0){
				dp[i][j] = a[i];
			}
			else{
				dp[i][j] = max(a[i]+min(dp[i+2][j],dp[i+1][j-1]),a[j]+min(dp[i][j-2],dp[i+1][j-1]));
			}
		}
	}
	ll x = dp[0][n-1];
	/*
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        cout<<dp[i][j]<<" ";
	    }
	    cout<<endl;
	}*/
	cout<<2*x-sum;
	
}
