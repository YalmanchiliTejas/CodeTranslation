#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>
#define inputarr(a,n) for(ll i=0;i<n;i++) cin>>a[i];
#define prllarr(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<" ";
#define pb push_back
#define ll long long
#define mod 1000000007
#define foi ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define in(n) scanf("%lld",&n);
#define in2(x,y) scanf("%lld %lld",&(x),&(y));
#define in3(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z));
#define out(n) printf("%lld\n",n);
#define out2(x,y) printf("%lld %lld\n",x,y);
#define test(t)  ll t; in(t);while(t--)
#define set(arr,n,s) for(ll i=0;i<n;i++){arr[i]=s;}


ll power(ll x,ll y,ll p){ll res=1;x=x%p;while(y>0){if(y&1){res=(res*x)%p;} y=y>>1;x=(x*x)%p;}return res;}
ll modInverse(ll a,ll p){return power(a,p-2,p);}//used with feemat little

ll gcd(ll x,ll y){if(x==0 || y==0){return max(y,x);}return gcd(y%x,x);}
ll gcdExtended(ll a,ll b,ll &x,ll &y){if(a==0){x=0;y=1;return b;}ll x1,y1;ll gcd = gcdExtended(b%a,a,x1,y1);x=y1-(b/a)*x1;y=x1;return gcd;}//o(log(b))
;
void prac(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   #endif 
}
string k;ll d;
ll size;
ll dp[10005][2][102];
ll solve(ll index,ll active,ll sum){
	if(index==size){
		return (sum==0);
		
	}
	// cout<<sum<<endl;
	if(dp[index][active][sum]!=-1)return dp[index][active][sum];
	ll ret=0;
	ll cur=k[index]-'0';
	if(!active){
		cur=9;
	}
	for(ll i=0;i<=cur;i++){
		ret+=solve(index+1,(active)&(i==cur),(sum+i)%d);
		// cout<<sum<<" "<<ret<<endl;
		ret%=mod;
	}
	dp[index][active][sum]=ret;
	return ret;




}






int main() 
{
  	// prac();
  
  	cin>>k;
  	for(ll i=0;i<=10000;i++)for(ll j=0;j<2;j++)for(ll k=0;k<=100;k++)dp[i][j][k]=-1;
  	in(d)
  	ll ans=0;
  	size=k.size();
  	for(ll i=0;i<=(k[0]-'0');i++)
  	{
  		ans+=solve(1,i==(k[0]-'0'),(i)%d);
  		// cout<<i<<" "<<ans<<endl;
  		ans%=mod;
  	}
  	// cout<<ans<<endl;
  	out((ans-1+mod)%mod);



  	

}
/*error-----
convert every int to long long eg-1LL
create array with proper analysis of problem constrain
check mod also
*/




