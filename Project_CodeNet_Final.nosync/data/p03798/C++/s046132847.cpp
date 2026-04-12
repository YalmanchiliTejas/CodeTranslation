#include<bits/stdc++.h>
using namespace std;
const int pi=3.1415926535897932384626433832795;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
#define ll long long
#define inf int(1e9+7)
#define pb push_back
#define mp make_pair
char s[100005];
char t[100005];
int a[100005],n;
int main()
{
	cin>>n>>s;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
		{
			if(i==0)
				a[0]=0;
			else
				a[0]=1;
			if(j==0)
				a[1]=0;
			else
				a[1]=1;
			for(int k=2;k<n;k++)
			{
				if(s[k-1]=='o')
				{
					if(a[k-1]==0)
						a[k]=a[k-2];
					else
						a[k]=1-a[k-2];
				}
				else
				{
					if(a[k-1]==0)
						a[k]=1-a[k-2];
					else
						a[k]=a[k-2];
				}
			}
			if(s[n-1]=='o')
			{
				if(a[n-1]==0)
				{
					if(a[n-2]!=a[0])
						continue;
				}
				else
				{
					if(a[n-2]==a[0])
						continue;
				}
			}
			else
			{
				if(a[n-1]==0)
				{
					if(a[n-2]==a[0])
						continue;
				}
				else
				{
					if(a[n-2]!=a[0])
						continue;
				}
			}
			if(s[0]=='o')
			{
				if(a[0]==0)
				{
					if(a[n-1]!=a[1])
						continue;
				}
				else
				{
					if(a[n-1]==a[1])
						continue;
				}
			}
			else
			{
				if(a[0]==0)
				{
					if(a[n-1]==a[1])
						continue;
				}
				else
				{
					if(a[n-1]!=a[1])
						continue;
				}
			}
			for(int k=0;k<n;k++)
			{
				if(a[k]==0)
					t[k]='S';
				else
					t[k]='W';
			}
			cout<<t;
			return 0;
		}
	puts("-1");
	return 0;
}