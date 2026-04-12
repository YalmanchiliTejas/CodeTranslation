#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout<<#a<<":"<<a<<endl;
const ll INF=0x3f3f3f3f;
const ll N=1e6+7;
const ll mod=1e9+7;
ll maxn,minn;
ll T,n,m,k;
string s;
ll arr[N];
ll dp[10010][110][2];

ll dfs(ll a,ll b,ll c){
	ll d,ans=0,bb;
	if(dp[a][b][c]!=-1){
		return dp[a][b][c];
	}
	if(a==n+1){
		if(b==0){
			return dp[a][b][c]=1;
		}
		else{
			return dp[a][b][c]=0;
		}
	}
	if(c==1){
		d=arr[a];
	}
	else{
		d=9;
	}
	for(ll i=0;i<=d;i++){
		bb=(b+i)%k;
		dp[a+1][bb][c&(i==d)]=dfs(a+1,bb,c&(i==d));
		ans=(ans+dp[a+1][bb][c&(i==d)])%mod;
	}
	return dp[a][b][c]=ans;
}

int main(){
	cin>>s>>k;
	n=s.size();
	for(ll i=1;i<=n;i++){
		arr[i]=s[i-1]-'0';
	}
	memset(dp,-1,sizeof(dp));
	
	printf("%lld\n",(dfs(1,0,1)-1+mod)%mod);

	return 0;
}



