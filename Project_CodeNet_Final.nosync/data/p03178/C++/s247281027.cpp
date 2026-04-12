#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define ll long long
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
const ll mod=1e9+7;
const int N=1e5+4;

ll n,mod1,dp[N][150][2],ans1;
string str;

ll dpf(ll i,ll sum,bool flag){
	if(i==n){
		if(sum==0){
			return 1;
		}
		return 0;
	}
	if(dp[i][sum][flag]!=-1)return dp[i][sum][flag]%mod;

	ll ans=0,sa;
	if(flag)sa=str[i]-'0';
	else sa=9;

	for(int j=0;j<=sa;j++){
		ans+=dpf(i+1,(sum+j)%mod1,sa==j && flag)+mod;
		ans%=mod;
	}
	dp[i][sum][flag]=(ans+mod)%mod;
	return dp[i][sum][flag];
}

int main(){
	//fri("in.txt");
	//fro("out.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>str>>mod1;
	n=str.length();
	memset(dp,-1,sizeof(dp));
	ans1=dpf(0,0,1)-1;
	cout<<(ans1+mod)%mod;

return 0;
}
