#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define pint pair<int,int>
using namespace std;

ll dp[3001][3001],a[3001];

ll fun(int s, int e){
	if(s>e)	return 0;
	if(s==e)	return a[s];
	if(dp[s][e]!=-1)	return dp[s][e];
	ll a1=min(fun(s+1,e-1)+a[s]-a[e], fun(s+2,e)+a[s]-a[s+1]);
	ll a2=min(fun(s+1,e-1)+a[e]-a[s], fun(s,e-2)+a[e]-a[e-1]);
	dp[s][e]=max(a1,a2);
	return dp[s][e];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,i,j;	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			dp[i][j]=-1;
		}
	}
	cout<<fun(1,n)<<endl;
	return 0;
}