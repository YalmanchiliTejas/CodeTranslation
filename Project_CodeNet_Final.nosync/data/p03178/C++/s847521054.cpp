#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod=1000000007;
void add(ll& a, ll b)
{
	a+=b;
	if(a>=mod)
		a-=mod;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.txt","r",stdin);
	char k[10110];
	cin>>k;
	ll d;
	cin>>d;
	ll len=strlen(k);
	vector<vector<ll>> dp(d,vector<ll>(2));
	dp[0][0]=1;
	for(ll i=0;i<len;i++)
	{
		vector<vector<ll>> newdp(d,vector<ll>(2));
		for(ll sum=0;sum<d;sum++)
		{
			for(bool small_already : {false,true})
			{
				for(ll digit=0;digit<10;digit++)
				{
					if(digit>k[i]-'0'&&!small_already)
						break;
					add(newdp[(sum+digit)%d][small_already||(digit<k[i]-'0')],dp[sum][small_already]);
				}
			}
		}
		dp=newdp;
	}
	ll ans=0;
	ans=(dp[0][0]+dp[0][1])%mod;
	ans-=1;
	if(ans==-1)
		cout<<mod-1<<endl;
	else
		cout<<ans<<endl;


}