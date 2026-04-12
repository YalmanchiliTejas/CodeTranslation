#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,a[3002],dp[3002][3002];
bool f[3002][3002];
ll Comp(int l,int r) {
	int p=(n-(r-l+1))%2;
	if (f[l][r]) return dp[l][r];
	if (l==r && p%2==0) return dp[l][r]=a[l]; 
	if (l==r && p%2) return dp[l][r]=-a[l];  
	
	f[l][r]=1;
	
	ll x=Comp(l,r-1);
	ll y=Comp(l+1,r);
	ll AnsT=max(x+a[r],y+a[l]);
	ll AnsJ=min(x-a[r],y-a[l]);
	
	if (p%2==0) return dp[l][r]=AnsT;
	if (p%2) return dp[l][r]=AnsJ;
}

main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	
	for (int i=1; i<=n; i++) 
		cin>>a[i];
	
	cout<<Comp(1,n)<<endl;
}