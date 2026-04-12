#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n,a[2][555],b[2][555],is[2][555],dd[555][555],ans[555][555];
void jh()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			swap(dd[i][j],dd[j][i]);
		}
	}
}
bool sl()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			dd[i][j]=-1;
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
			int nw=is[i][j];
			if(a[i][j]!=nw)
			{
				for(int k=0;k<n;k++)
				{
					if(dd[j][k]==!nw)
					{
						return false;
					}
					dd[j][k]=nw;
				}
			}
		}
		jh();
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<n;k++)
			{
				int nw=is[j][k];
				if(a[j][k]==nw)
				{
					vector<int>vv;
					bool ok=false;
					for(int l=0;l<n;l++)
					{
						if(dd[k][l]==-1)
						{
							vv.push_back(l);
						}
						if(dd[k][l]==nw)
						{
							ok=true;
						}
					}
					if(ok)
					{
						continue;
					}
					if(vv.size()==0)
					{
						return false;
					}
					if(vv.size()==1)
					{
						dd[k][vv[0]]=nw;
					}
				}
			}
			jh();
		}
	}
	vector<int>v1,v2;
	for(int i=0;i<n;i++)
	{
		bool fl=true;
		for(int j=0;j<n;j++)
		{
			if(dd[i][j]==-1)
			{
				fl=false;
			}
		}
		if(!fl)
		{
			v1.push_back(i);
		}
	}
	for(int j=0;j<n;j++)
	{
		bool fl=true;
		for(int i=0;i<n;i++)
		{
			if(dd[i][j]==-1)
			{
				fl=false;
			}
		}
		if(!fl)
		{
			v2.push_back(j);
		}
	}
	for(int i=0;i<v1.size();i++)
	{
		for(int j=0;j<v2.size();j++)
		{
			dd[v1[i]][v2[j]]=(i+j)%2;
		}
	}
	return true;
}
signed main()
{
	cin>>n;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>b[i][j];
		}
	}
	for(int bt=0;bt<64;bt++)
	{
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<n;j++)
			{
				is[i][j]=b[i][j]>>bt&1;
			}
		}
		if(!sl())
		{
			cout<<-1<<endl;
			return 0;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				ans[i][j]|=1LL*(dd[i][j])<<bt;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<ans[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}