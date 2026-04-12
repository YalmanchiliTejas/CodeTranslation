#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define double long double
#define x first
#define y second
#define long long long
#define int long 



           //       |----|       /\      |    |   -----   |
           //       |   /       /  \     |    |     |     |
           //       |--/       /----\    |----|     |     |
           //       |   \     /      \   |    |     |     |
           //       |    \   /        \  |    |   -----   -------

string s;
int d,n;
int cache[10002][102][2][2];
int modu=1000000007;
int dp(int pos,int mod,int less,int marked)
{
	if(pos==n)
	{
		if(mod==0&&marked==1)
			return 1;
		return 0;
	}
	if(cache[pos][mod][less][marked]!=-1)
		return cache[pos][mod][less][marked];
	if(less==1)
	{
		int ans=0;
		for(int i=0;i<=9;i++)
		{
			if(i!=0)
			ans+=dp(pos+1,(mod+i)%d,1,1);
			else
			ans+=dp(pos+1,(mod+i)%d,1,marked);	
			if(ans>modu)
				ans%=modu;
		}
		return cache[pos][mod][less][marked]=ans;
	}
	else
	{
		int ans=0;
		for(int i=0;i<=s[pos]-48;i++)
		{
			if(i!=s[pos]-48)
			{
				if(i==0)
				ans+=dp(pos+1,(mod+i)%d,1,marked);
				else
				ans+=dp(pos+1,(mod+i)%d,1,1);
			}
			else
			{
				if(i==0)
				ans+=dp(pos+1,(mod+i)%d,0,marked);
				else
				ans+=dp(pos+1,(mod+i)%d,0,1);	
			}
			if(ans>modu)
				ans%=modu;
		}
		return cache[pos][mod][less][marked]=ans;
	}

}
int32_t main()
{
    IOS
    cin>>s;
    n=s.length();
    cin>>d;
    memset(cache,-1,sizeof(cache));
    cout<<dp(0,0,0,0);
}