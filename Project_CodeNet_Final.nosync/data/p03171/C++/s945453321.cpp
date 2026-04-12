#include<bits/stdc++.h>
#define ll long long int
using namespace std;


ll dp[3001][3001][2]={0};
ll find(vector<ll>&v,ll l,ll r,ll chance){
	if(l>r) return 0;
	ll &ans=dp[l][r][chance];
	if(ans!=-1) return ans;
	if(chance==0){
		ans=max(v[l]+find(v,l+1,r,1-chance),v[r]+find(v,l,r-1,1-chance));
	}
	else{
		ans=min(-v[l]+find(v,l+1,r,1-chance),-v[r]+find(v,l,r-1,1-chance));
	}
	return ans;
}
int  main(){
		ll n;
		cin>>n;
		vector<ll>v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				dp[i][j][0]=-1;
				dp[i][j][1]=-1;
			}
		}
		cout<<find(v,0,n-1,0)<<endl;
}
