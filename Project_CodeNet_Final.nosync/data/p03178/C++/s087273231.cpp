#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e4+5;
const int M=105;
const int MOD=1e9+7;

string n;
int d;
int cache[N][M][2];
int sz=0, x[N];

int dp(int idx, int rem, int less)
{
	if(idx==sz+1)
		return (rem==0);
	int &ans=cache[idx][rem][less];
	if(ans!=-1)
		return ans;
	ans=0;
	if(!less)
	{
		for(int i=0;i<=x[idx];i++)
			ans+=dp(idx+1, (rem+i)%d, less|(i<x[idx]));
	}
	else
	{
		for(int i=0;i<=9;i++)
			ans+=dp(idx+1, (rem+i)%d, 1);
	}
	ans%=MOD;
	return ans;
}

int f(string &s)
{
	sz=s.size();
	for(int i=1;i<=sz;i++)
		x[i]=(s[i-1]-'0');
	memset(cache, -1, sizeof(cache));
	return dp(1, 0, 0);
}

int32_t main()
{
	IOS;
	cin>>n>>d;
	int ans=f(n);
	ans-=1;
	ans+=MOD;
	ans%=MOD;
	cout<<ans;
	return 0;
}