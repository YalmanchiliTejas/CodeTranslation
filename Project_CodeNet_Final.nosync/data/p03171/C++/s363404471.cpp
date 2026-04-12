#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int const MAXN=3100;
int n, v[MAXN]; 
ll pre[MAXN], memo[MAXN][MAXN];
ll sum(int l, int r){
	return (l==0?pre[r]:pre[r]-pre[l-1]);
}
ll dp(int l, int r){
	if(memo[l][r]!=-1) return memo[l][r];
	if(l==r) return v[l];
	return memo[l][r]=max(v[l]+sum(l+1,r)-dp(l+1,r), v[r]+sum(l,r-1)-dp(l,r-1));
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i];
		pre[i]=v[i];
		if(i!=0) pre[i]+=pre[i-1];	
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			memo[i][j]=-1;
	cout<<dp(0,n-1)-(pre[n-1]-dp(0,n-1));
}