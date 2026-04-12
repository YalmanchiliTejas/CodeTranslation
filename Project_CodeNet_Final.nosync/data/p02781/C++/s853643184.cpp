#include<bits/stdc++.h>
#define ll 				long long
#define ld 				long double
#define fastio 			ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define debug(x) 		cerr<<#x<<" "<<x<<endl
#define cina(a,n) 		for(ll i = 0;i<n;i++)	cin>>a[i];
#define couta(a,n) 		for(ll i = 0;i<n;i++) cout<<a[i]<<" ";
#define fauto(ar)		for(auto x : ar)	cout<<x<<" ";
#define mod 			1000000007
#define siz 			105
#define f 				first
#define s 				second
#define pb 				push_back
#define endl 			"\n"
#define ci 				cin.ignore()
using namespace std;
ll dp[105][4][2];
ll getans(string num,ll k,ll pos,bool limit)
{
	if(k == 0)
		return 1;
	if(pos == num.length())
		return 0;
	
	if(dp[pos][k][limit] != -1)
	return dp[pos][k][limit];
	
	ll ans = 0,i;
	if(limit)
	{
		if(num[pos] == '0')
		{
			ans += getans(num,k,pos+1,1);
		}
		else
		{
			ans += getans(num,k,pos+1,0);
			for(i = 1;i<num[pos]-'0';i++)
			ans += getans(num,k-1,pos+1,0);
			ans += getans(num,k-1,pos+1,1);
		}	
		
	
	}
	else
	{
		ans += getans(num,k,pos+1,0);
		for(i = 1;i<=9;i++)
		ans += getans(num,k-1,pos+1,0);
	}
	
	return dp[pos][k][limit] = ans;
}
int main()
{
	string num;
	ll k,i,j;
	cin>>num>>k;
	
	memset(dp,-1,sizeof(dp));
	cout<<getans(num,k,0,1);
	
	
	
}