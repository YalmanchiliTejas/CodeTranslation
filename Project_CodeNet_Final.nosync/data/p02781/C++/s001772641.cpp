#include<bits/stdc++.h>
using namespace std;

int d,k;
string b;
int n;
vector<char> v;
int dp[10000][10000][2];
int solve(int i,int cnt,int f)
{
	if(i==n)
	{
		if(cnt==k)
		{
			return 1;
		}
		return 0;
	}
	if(cnt>k)
	{
		return 0;
	}
	if(dp[i][cnt][f]!=-1)
	{
		return dp[i][cnt][f];
	}
	int limit=9;
	if(!f)
	{
		limit=v[i]-'0';
	}
			int ans=0;
	for(int digit=0;digit<=limit;digit++)
	{
			int new_cnt=cnt;
			int new_flag=f;
		if(digit>0)
		{
			new_cnt++;
		}
		if(f==0 && digit<limit)
		{
			new_flag=1;
		}
		if(new_cnt<=k)
		ans+=solve(i+1,new_cnt,new_flag);
	}

	return dp[i][cnt][f]=ans;
}
int main()
{
	cin>>b>>k;
	for(int i=0;i<b.size();i++)
	{
		v.push_back(b[i]);
	}
//	reverse(v.begin(),v.end());
	n=v.size();
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,0,0);
}