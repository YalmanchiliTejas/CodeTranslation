#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
int main() {
	ll n;
	cin>>n;
	ll arr[n];
	
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	ll dp[n][n];
	
	for(int i=0;i<n;i++)
	dp[i][i]=arr[i];
	
	for(int d=1;d<n;d++){
	    for(int i=0;i<n-d;i++){
	        dp[i][i+d]=max(arr[i]-dp[i+1][i+d],arr[i+d]-dp[i][i+d-1]);
	    }
	}
	
	cout<<dp[0][n-1];
	
	return 0;
}