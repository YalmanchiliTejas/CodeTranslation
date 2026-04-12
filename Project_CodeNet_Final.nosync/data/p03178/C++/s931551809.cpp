/*
ABHIJEET BISWAS
CSE 4th SEM 
MNNIT ALLAHBAD
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (int )1e18
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pli pair<long long,int>
#define pll pair<long long,long long>
#define MAX 1000009
#define pb push_back
#define mp map<int,int>
#define f first
#define s second
#define popi __builtin_popcount
#define popll __builtin_popcountll
#define grp vector<int> graph[MAX];
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ld pi=2.0*acos(0.0);
int dp[10004][102][2];
string in;
int n,d;
int solve(int id,int rem,int m)
{
	if(id>=n)
	{
		if(rem==0)
		return 1;
		return 0;
	}
	int &curr=dp[id][rem][m];
	if(curr!=-1)
	return curr;
	curr=0;
	if(m)
	{
		for(int i=0;i<=in[id]-'0';i++)
		{
			if(i==in[id]-'0')
				curr=(curr+solve(id+1,(rem+i)%d,1))%MOD;
			else
				curr=(curr+solve(id+1,(rem+i)%d,0))%MOD;
		}
	}
	else
	{
		for(int i=0;i<=9;i++)
		curr=(curr+solve(id+1,(rem+i)%d,0))%MOD;
	}
	return curr;
}
int main() {
	fastIO
	cin>>in>>d;
	n = in.size();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<d;j++)
		for(int k=0;k<2;k++)
		dp[i][j][k]=-1;
	}
	cout<<(solve(0,0,1)+MOD-1)%MOD<<endl;
	return 0;
}