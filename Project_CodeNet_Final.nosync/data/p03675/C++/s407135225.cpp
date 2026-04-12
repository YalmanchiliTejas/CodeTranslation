#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<complex>
#include<string>
#include<cstring>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
#define INF 100000000
#define debug(x) cout<<#x<<": "<<x<<endl

#define all(x) x.begin(),x.end()
typedef pair<int,int> P;
typedef pair<int,P> PP;
int n;
int a[300000];
int flag;
vector<int> ans;
int main()
{
	cin>>n;
	rep(i,n)cin>>a[i];
	if(n%4==0)
	{
		for(int i=n-1;i>=0;i-=2)
		{
			ans.push_back(a[i]);
			//cout<<a[i]<<" ";
		}
		for(int i=0;i<n;i+=2)
		{
			ans.push_back(a[i]);
			}
		
	}
	if(n%4==1)
	{
		for(int i=n-2;i>=0;i-=2)
		{
			ans.push_back(a[i]);
			//cout<<a[i]<<" ";
		}
		for(int i=0;i<n;i+=2)
		{
			ans.push_back(a[i]);
			}
	}
	if(n%4==2)
	{
		for(int i=n-1;i>=0;i-=2)
		{
			//cout<<a[i]<<" ";
			ans.push_back(a[i]);
		}
		for(int i=0;i<n;i+=2)
		{
			ans.push_back(a[i]);
			}
	}
	if(n%4==3)
	{
		for(int i=n-2;i>=0;i-=2)
		{
			ans.push_back(a[i]);
			//cout<<a[i]<<" ";
		}
		for(int i=0;i<n;i+=2)
		{
			ans.push_back(a[i]);
			}
	}
	if(n%2==0)
	{
		rep(i,n)
		{
			cout<<ans[i];
			if(i==n-1)cout<<endl;
			else cout<<" ";
		}
	}
	else
	{
		for(int i=n-1;i>=0;i--)
		{
			cout<<ans[i];
			if(i==0)cout<<endl;
			else cout<<" ";
		}
	}
	return 0;
}