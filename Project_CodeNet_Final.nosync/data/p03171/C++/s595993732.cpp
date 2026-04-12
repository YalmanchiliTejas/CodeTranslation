#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<string.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);

ll dp[3000][3000] = {};
ll a[3000];

ll max(ll a,ll b){
	return a>=b?a:b;
}
ll min(ll a,ll b){
	return a<=b?a:b;
}

ll rec(int i, int j){
	if(i>j) return 0;
	if(i==j) return a[i];
	if(i+1==j) return max(a[i],a[j]);
	ll& ans = dp[i][j];
	if(ans!=-1)return ans;

	ans = max(a[i] + min(rec(i+1,j-1),rec(i+2,j)), a[j] + min(rec(i+1,j-1),rec(i,j-2)) );
	return ans;

}


int main(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin >> n;
	ll sum = 0;
	for(int i=0;i < n ; ++i){
		cin >> a[i];
		sum+= a[i];
	}

	ll X = rec(0,n-1);
	ll Y = sum-X;

	cout << X-Y << endl;

}