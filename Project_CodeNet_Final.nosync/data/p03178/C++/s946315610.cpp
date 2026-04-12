#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define inf 1000000000000000000
#define fr first
#define sc second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pll pair<ll,ll>
#define vll vector<ll>
#define umap unordered_map<ll,ll>
#define lpq priority_queue<ll,vector<ll>,greater<ll>>
ll globe=0;
ll powe(ll n,ll r){if(!r)return 1;else if(r%2==0)return powe(n*n,r/2);else return n*powe(n*n,(r-1)/2);}

ll digitDP(vector<vector<vll>> &dp,ll x,ll y,ll p,string &s,ll val){
	if(x>=s.size()){
		if(y%val==0)
			return 1;
		else
			return 0;
	}
	if(dp[x][y][p]!=-1)
		return dp[x][y][p];
	ll ans=0;
	if(p==0){//string till x is equal
		for(ll i=0;i<s[x]-'0';i++){
			ans+=digitDP(dp,x+1,(y+i)%val,1,s,val)%mod;
		}
		ans+=digitDP(dp,x+1,(y+s[x]-'0')%val,0,s,val)%mod;
	}
	else{
		for(ll i=0;i<10;i++){
			ans+=digitDP(dp,x+1,(y+i)%val,1,s,val)%mod;
		}
	}
	return dp[x][y][p]=ans%mod;
}

int main(){
	/*
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t=1;
	//cin>>t;
	while(t--){
		string s;
		ll val;
		cin>>s>>val;
		ll y=0;
		vector<vector<vll>> dp(s.size(),vector<vll> (val,vll (2,-1)));
		ll ans=digitDP(dp,0,y,0,s,val)%mod;
		//cout<<dp[15][4][0]<<endl;
		cout<<(ans-1+mod)%mod<<endl;
	}

	return 0;

}