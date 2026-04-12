#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int dp[30001][1002][2];
int countdigitsum(int pos,int d,bool tight,string k,int D){
	int ub = tight? k[pos]-'0': 9;
	if(dp[pos][d][tight]!=-1){
		return dp[pos][d][tight];
	}
	if(pos==k.length()-1){
		int ans=0;
		for(int x=0;x<=ub;x++){
			if(x%D==d){
				ans++;
			}
		}
		return ans;
	}
	int ans=0;
	for(int x=0;x<=ub;x++){
		ans= (ans+countdigitsum(pos+1,(D+d-x%D)%D,tight&&(x==ub),k,D))%mod;
	}
	return dp[pos][d][tight]=ans;
}
signed main(){
	string k;
	cin>>k;
	int D;
	cin>>D;
	memset(dp,-1,sizeof dp);

	cout<<(mod+countdigitsum(0,0,1,k,D)-1)%mod<<endl;
	return 0;
}