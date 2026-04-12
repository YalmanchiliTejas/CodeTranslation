#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=505;
int n,s[N],t[N],u[N],v[N],ans[N][N],a[N][N];
vector<pair<int,int>>r,c;
inline void zh(){cout<<-1<<endl;exit(0);}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>t[i];
	for(int i=1;i<=n;i++)
		cin>>u[i];
	for(int i=1;i<=n;i++)
		cin>>v[i];
	for(int i=0;i<64;i++)
	{
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				a[j][k]=-1;
		r.clear();
		c.clear();
		for(int j=1;j<=n;j++)
		{
			if(!s[j])
			{
				if((u[j]>>i)&1)
					for(int k=1;k<=n;k++)
						a[j][k]=1;
				else
					r.emplace_back(j,0);
			}
			else
			{
				if((~u[j]>>i)&1)
					for(int k=1;k<=n;k++)
						a[j][k]=0;
				else
					r.emplace_back(j,1);
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(!t[j])
			{
				if((v[j]>>i)&1)
				{
					for(int k=1;k<=n;k++)
						if(a[k][j]==0)
							zh();
					for(int k=1;k<=n;k++)
						a[k][j]=1;
				}
				else
					c.emplace_back(j,0);
			}
			else
			{
				if((~v[j]>>i)&1)
				{
					for(int k=1;k<=n;k++)
						if(a[k][j]==1)
							zh();
					for(int k=1;k<=n;k++)
						a[k][j]=0;
				}
				else
					c.emplace_back(j,1);
			}
		}
		if(min(r.size(),c.size())>=2)
		{
			for(int j=0;j<r.size();j++)
				for(int k=0;k<c.size();k++)
					a[r[j].first][c[k].first]=(j+k)&1;
		}
		else if(r.size()==1)
		{
			for(auto p:c)
			{
				int fl=0;
				for(int j=1;j<=n;j++)
					fl|=a[j][p.first]==p.second;
				a[r[0].first][p.first]=fl?r[0].second:p.second;
			}
			int fl=0;
			for(int j=1;j<=n;j++)
				fl|=a[r[0].first][j]==r[0].second;
			if(!fl)
				zh();
		}
		else if(c.size()==1)
		{
			for(auto p:r)
			{
				int fl=0;
				for(int j=1;j<=n;j++)
					fl|=a[p.first][j]==p.second;
				a[p.first][c[0].first]=fl?c[0].second:p.second;
			}
			int fl=0;
			for(int j=1;j<=n;j++)
				fl|=a[j][c[0].first]==c[0].second;
			if(!fl)
				zh();
		}
		else
		{
			for(auto p:r)
			{
				int fl=0;
				for(int j=1;j<=n;j++)
					fl|=a[p.first][j]==p.second;
				if(!fl)
					zh();
			}
			for(auto p:c)
			{
				int fl=0;
				for(int j=1;j<=n;j++)
					fl|=a[j][p.first]==p.second;
				if(!fl)
					zh();
			}
		}
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				ans[j][k]|=(a[j][k]&1)<<i;
	}
	for(int j=1;j<=n;j++)
	{
		for(int k=1;k<=n;k++)
			cout<<ans[j][k]<<' ';
		cout<<endl;
	}
	return 0;
}