#include<bits/stdc++.h>
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ms memset
#define MOD 1000000007
#define sp fixed<<setprecision
#define sz sizeof
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
bool pr[1000007];
ll fpow(ll x,ll y){x=x%MOD;ll res=1;while(y){if(y&1)res=res*x;res%=MOD;y=y>>1;x=x*x;x%=MOD;}return res;}
ll inv(ll a,ll m=MOD){ll c=m;ll y=0,x=1;if(m==1)return 0;while(a>1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=c;return x;}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll a[n];
	ll sum=0;
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	sum+=a[i];
}
ll dp[n][n];
for(int i=n-1;i>=0;i--)
{
	for(int j=i;j<n;j++)
	{
		if(i==j)
		dp[i][j]=a[i];
		else if(j==i+1)
		dp[i][j]=max(a[i],a[j]);
		else
		{
			ll choice1=a[i]+min(dp[i+2][j],dp[i+1][j-1]);
			ll choice2=a[j]+min(dp[i][j-2],dp[i+1][j-1]);
			dp[i][j]=max(choice1,choice2);
		}
	}
}
cout<<2*dp[0][n-1]-sum;
}
