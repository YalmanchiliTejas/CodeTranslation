//** aman**/
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define dl          double
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define lb lower_bound
#define ub upper_bound
#define bs          binary_search
#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
ll dp[10005][105][2],d;
void llialize(){
	for(ll i=0;i<10005;i++){
		for(ll j=0;j<105;j++){
			dp[i][j][0]=-1;
			dp[i][j][1]=-1;
		}
	}
}
ll digit(ll inx,ll sum,ll tem,vector<ll> &v){
	if(inx<0){
		if(sum%d==0)return 1LL;
		return 0LL;
	}
	if(dp[inx][sum][tem]!=-1&&tem==0)
	return dp[inx][sum][tem];
	ll k,res=0;
	k=(tem==1?v[inx]:9);
	for(ll dig=0;dig<=k;dig++){
		ll ntem=(dig==v[inx])?tem:0;
		res=(res+digit(inx-1,(sum+dig)%d,ntem,v))%hell;
	}
	if(!tem)dp[inx][sum][tem]=res;
	return res;
}
ll solve(string &x){
	vi v;
	for(ll i=x.size()-1;i>=0;i--){
		v.pb(x[i]-'0');
	}
	return digit(v.size()-1,0,1,v);
}
int main(){
	ios;
	ll t=1;
	llialize();
	while(t--){
		string r;cin>>r>>d;
		cout<<(solve(r)-1+hell)%hell<<endl;
	}
}
