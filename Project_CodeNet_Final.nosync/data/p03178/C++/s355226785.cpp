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
const int N=10005;

ll n,mod1,dp[N][105][2];
string str;

ll dpf(int i,int sum,bool flag){
	if(i==n){
		if(sum==0){
			return 1;
		}
		return 0;
	}
	if(dp[i][sum][flag]!=-1)return dp[i][sum][flag]%mod;

	ll ans=0;
	int sayi;
	if(flag)sayi=str[i]-'0';
	else sayi=9;

	for(int j=0;j<=sayi;j++){
		ans+=dpf(i+1,(sum+j+mod1)%mod1,sayi==j && flag);
		ans+=mod;
		ans%=mod;
	}
	dp[i][sum][flag]=(ans+mod)%mod;
	return dp[i][sum][flag];
}

int main(){
//	fri("in.txt");
//	fro("out.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>str>>mod1;
	n=str.length();
	memset(dp,-1,sizeof(dp));
	cout<<(dpf(0,0,1)-1+mod)%mod;

return 0;
}
