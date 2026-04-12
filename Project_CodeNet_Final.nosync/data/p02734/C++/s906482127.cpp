#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,s;
const int N=3009;
ll a[N],dp[N][N],cur_index;
const ll MOD=998244353;

ll func(int index,int required){
	if(required==0)	return n-(index-1);
	if(required<0 || index==n)	return 0;

	
	if(dp[index][required]!=-1)	return dp[index][required];

	ll ans=0;
	ans+=func(index+1,required);ans%=MOD;
	ans+=func(index+1,required-a[index]);ans%=MOD;

	return dp[index][required]=ans;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>s;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)	cin>>a[i];
	ll ans=0;
	for(int i=0;i<n;i++){
		ans+=func(i,s);
		ans%=MOD;
		// cout<<func(i,s)<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}