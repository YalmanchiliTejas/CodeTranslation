#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mn=1e5+7;
vector< vector<ll> > dp(mn);

ll dfs(ll a,ll b){
	ll ret=0;
	for(ll p=0;p<dp[a].size();++p){
		if(dp[a][p]==b)continue;
		ret+=dfs(dp[a][p],a);
	}
	if(ret>=2){cout<<"First"<<endl;exit(0);}
	if(ret==0)return 1;
	return 0;
}

int main(){
	ll N;cin>>N;
	for(ll a=0;a<N-1;++a){
		ll b,c;cin>>b>>c;
		--b;--c;
		dp[b].push_back(c);
		dp[c].push_back(b);
	}
	if(dfs(0,0))cout<<"First"<<endl;
	else cout<<"Second"<<endl;
	return 0;
}
