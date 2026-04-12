#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define vll vector<ll>
#define M 100011
#define MOD 1000000007
ll md=MOD;
string s1;

ll a[10110];
ll dp[10110][110][2];
ll f(ll x,ll mod,ll k,ll m,ll sum){
	if(x<0){if(mod==0){return 1;}return 0;}
	if(dp[x][mod][k]!=-1&&k==0)return dp[x][mod][k];
	ll mx=9;
	if(k==1)mx=a[x];
	ll ans=0;
	for(ll i=0;i<=mx;++i){
		ll nc=0;
		if(i==a[x])nc=k;
		ans+=f(x-1,(mod+i)%m,nc,m,10*sum+i)%md;
		ans%=md;
	}
	dp[x][mod][k]=ans%md;
	return ans%md;

}


int main()
{

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll t,i,j,m,x,y,n,z,p,k,T;string s2,s3;x=1;
	cin>>s1>>m;
	n=s1.size();
	reverse(s1.begin(),s1.end());
	memset(dp,-1,sizeof(dp));
	for(i=0;i<n;++i)a[i]=s1[i]-'0';
	cout<<(f(n-1,0,1,m,0)%md-1+md)%md; 












	
	return 0;
}