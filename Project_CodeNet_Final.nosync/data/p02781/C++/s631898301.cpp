#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"

ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
ll ansfunc(string n,int k)
{
	if(n.length()<k)return 0;
	if(k==1)
	{
		string t=n;t.erase(t.begin());
		if(n[0]!='0')
			return (n[0]-'0')+(n.length()-1)*9;
		else return ansfunc(t,1);
	}
	if(k==2)
	{
		ll ans=0;
		string t=n;t.erase(t.begin());
		if(n[0]!='0')
		{
			ans+=(n[0]-'0'-1)*(n.length()-1)*9;ans+=(n.length()-2)*(n.length()-1)/2*81;
			ans+=ansfunc(t,1);
		}
		else
		ans+=ansfunc(t,2);
		return ans;
	}
	if(k==3)
	{
		ll ans=0,len=n.length();
		string t=n;t.erase(t.begin());
		if(n[0]!='0')
		{
			ans+=(n[0]-'0'-1)*(len-1)*(len-2)/2*81;ans+=(n.length()-1)*(n.length()-2)*(n.length()-3)/6*9*9*9;
			ans+=ansfunc(t,2);
		}
		else
		ans+=ansfunc(t,3);
		return ans;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string n;
	int k;
	cin>>n>>k;
	cout<<ansfunc(n,k);
	return 0;
}
