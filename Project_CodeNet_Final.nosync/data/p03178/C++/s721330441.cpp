// This question is quite tough for me. I am not able to get it.
// Can Anyone Help me
// https://atcoder.jp/contests/dp/tasks/dp_s
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MOD=1e9+7;
ll dp[10001][101][2];
ll solve(string& k,int D,int pos,int d,bool tight){
	if(dp[pos][d][tight]!=-1)
		return dp[pos][d][tight];
	int ub=(tight)?(k[pos]-'0'):9;
	if(pos==k.length()-1){
		ll ans=0;
		for(int x=0;x<=ub;++x)
			if(x%D==d)
				ans++;
		return ans;
	}
	ll ans=0;
	for(int x=0;x<=ub;x++){
		ans=(ans+solve(k,D,pos+1,(D+d-x%D)%D,tight && (x==ub)))%MOD;
	}
	return dp[pos][d][tight]=ans;
}

int main(){
	int D=0;string k;
	cin>>k>>D;
	memset(dp,-1,sizeof(dp));
	cout<<(MOD+solve(k,D,0,0,1)-1)%MOD<<'\n';
	return 0;
}