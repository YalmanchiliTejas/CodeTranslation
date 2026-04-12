#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[105][5];
ll sol[105][5];
string N;
int l;
ll solve(int i, int k)
{
	if(i==0)
		return k==0;
	if(k<0)
		return 0;
	if(sol[i][k]!=-1)
		return sol[i][k];
	sol[i][k] = solve(i-1,k);
	sol[i][k] += 9*solve(i-1,k-1);
	return sol[i][k];
}
ll getAns(int i, int k)
{
	if(i==l)
		return (k==0);
	if(N[i]=='0')
		return getAns(i+1,k);
	if(dp[i][k]!=-1)
		return dp[i][k];
	dp[i][k] = solve(l-i-1,k);
	for(auto c='1'; c<N[i]; c++){
		dp[i][k] += solve(l-i-1,k-1);
	}
	dp[i][k] += getAns(i+1,k-1);
	return dp[i][k];
}
int countA(int x)
{
	int c=0;
	while(x>0)
	{
		int r = x%10;
		c += (r!=0);
		x/=10;
	}
	return c;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll k;
	cin>>N;
	cin>>k;
	l = N.length();
	for(int i=0; i<=l; i++)
		for(int j=0; j<5; j++)
			sol[i][j]=-1,dp[i][j] = -1;
	if(l<4){
		int n = stoi(N);
		int ans=0;
		for(int i=1; i<=n; i++)
			ans += (countA(i)==k);
		cout<<ans<<"\n";
	}
	else
		cout<<getAns(0,k)<<endl;
}