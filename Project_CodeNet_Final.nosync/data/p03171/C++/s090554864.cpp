#include<bits/stdc++.h>
using namespace std;

#define ll long long int
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
const ll maxk = 3e3 + 2;
ll n;
ll dp[maxk][maxk];
bool vis[maxk][maxk];
ll v[maxk];
ll go(ll st=0,ll end=n-1)
{	
	if(vis[st][end])
	return dp[st][end];
	vis[st][end]=1;
	if(st==end)
	{
		return dp[st][end]=v[st];
	}
	return dp[st][end]=max(v[st]-go(st+1,end),v[end]-go(st,end-1));

}
int main()
{
	fast();
	cin>>n;
	
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
		
	}
	
	cout<<go()<<endl;
}