#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
string s;
ll d;
ll dp[10005][105][2];

ll solve(ll pos,ll sum,bool tight){
	if(pos==s.size())return sum==0;
	if(dp[pos][sum][tight]!=-1)
		return dp[pos][sum][tight];
	ll ans=0;
	ll end=((tight)?(s[pos]-'0'):9);
	for(ll i=0;i<=end;i++){
		ans=(ans+solve(pos+1,(sum+i)%d,tight&(i==end)))%mod;
	}
	return dp[pos][sum][tight]=ans;
}

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	

	cin>>s>>d;
	memset(dp,-1,sizeof(dp));
	cout<<(solve(0,0,1)-1+mod)%mod<<endl;
	return 0;
}