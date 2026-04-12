#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <stack>
#include <bitset>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define PI 3.1415926535897932384626433832795
#define inf 0x3f3f3f3f
#define MAXN 100005
using namespace std;
typedef long long ll;
const double EPS=1e-6;

int a[MAXN];
ll ans=-1;
int n;

void sp()
{
	vector<int>v;
	int i=0,j=n-1;
	int flag=0;//0 s 1 b
	while(i<=j)
	{
		if(!flag)
		{
			if(i==0)
				v.push_back(a[i++]);
			else
			{
				if(i<=j)
					v.push_back(a[i++]);
				if(i<=j)
					v.push_back(a[i++]);
			}
			flag=1;
		}else
		{
			if(i<=j)
				v.push_back(a[j--]);
			if(i<=j)
				v.push_back(a[j--]);
			flag=0;
		}			
	}
	
	vector <int>v1,v2;
	if(n&1)
	{
		for(i=1;i<n;i+=2)
		{
			v1.push_back(v[i]);
			v2.push_back(v[i+1]);
		}
		
		int t=v[0];
		v.clear();
		
		for(i=v1.size()-1;i>=0;i--)
			v.push_back(v1[i]);
		v.push_back(t);
		for(i=0;i<v2.size();i++)
			v.push_back(v2[i]);
	}else
	{
		for(i=0;i<n;i+=2)
		{
			v1.push_back(v[i]);
			v2.push_back(v[i+1]);
		}
		
		v.clear();
		
		for(i=v1.size()-1;i>=0;i--)
			v.push_back(v1[i]);
		for(i=0;i<v2.size();i++)
			v.push_back(v2[i]);
	}
	
	ll res=0;	
	for(i=0;i<v.size()-1;i++)
	{
	//	cout<<v[i+1]<<' '<<v[i]<<endl;
		res+=abs(v[i+1]-v[i]);
	}
	ans=max(ans,res);
}

void mp()
{
	vector<int>v;
	int i=0,j=n-1;
	int flag=1;//0 s 1 b
	while(i<=j)
	{
		if(!flag)
		{
			if(i<=j)
				v.push_back(a[i++]);
			if(i<=j)
				v.push_back(a[i++]);
			flag=1;
		}else
		{
			if(j==n-1)
				v.push_back(a[j--]);
			else
			{
				if(i<=j)
					v.push_back(a[j--]);
				if(i<=j)
					v.push_back(a[j--]);
			}
			flag=0;
		}			
	}
	
//	for(i=0;i<n;i++)
//		cout<<v[i]<<' ';
//	cout<<endl;
	
	vector <int>v1,v2;
	if(n&1)
	{
		for(i=1;i<n;i+=2)
		{
			v1.push_back(v[i]);
			v2.push_back(v[i+1]);
		}
		
		int t=v[0];
		v.clear();
		
		for(i=v1.size()-1;i>=0;i--)
			v.push_back(v1[i]);
		v.push_back(t);
		for(i=0;i<v2.size();i++)
			v.push_back(v2[i]);
	}else
	{
		for(i=0;i<n;i+=2)
		{
			v1.push_back(v[i]);
			v2.push_back(v[i+1]);
		}
		
		v.clear();
		
		for(i=v1.size()-1;i>=0;i--)
			v.push_back(v1[i]);
		for(i=0;i<v2.size();i++)
			v.push_back(v2[i]);
	}
	
	ll res=0;	
	for(i=0;i<v.size()-1;i++)
	{
	//	cout<<v[i+1]<<' '<<v[i]<<endl;
		res+=abs(v[i+1]-v[i]);
	}
	ans=max(ans,res);
}

int main()
{
	//ios::sync_with_stdio(false);
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	sort(a,a+n);
	
	sp();
	mp();
	printf("%lld",ans);
	return 0;
}
