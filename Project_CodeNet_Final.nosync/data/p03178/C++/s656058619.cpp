#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;

void add_mod(int &a,int b)
{
	a+=b;
	if(a>=mod)
	{
		a-=mod;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	string k;
	cin>>k;
	int d;
	cin>>d;
	vector< vector<int> >dp(d,vector<int>(2));
	dp[0][0]=1;
	for(int i=0;i<k.size();i++)
	{
		vector< vector<int> >temp(d,vector<int>(2));
		for(int sum=0;sum<d;sum++)
		{
			for(int st=0;st<2;st++)
			{
				for(int digit=0;digit<10;digit++)
				{
					if(digit>k[i]-'0' && st==0)
						break;
					add_mod(temp[(sum+digit)%d][st || (digit<k[i]-'0')],dp[sum][st]);
				}
			}
		}
		dp=temp;
	}
	ll ans=(dp[0][0]+dp[0][1])%mod;
	ans--;
	if(ans==-1)
	{
		ans=mod-1;
	}
	cout<<ans<<endl;
    return 0;
}