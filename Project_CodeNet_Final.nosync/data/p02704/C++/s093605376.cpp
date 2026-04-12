#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
//const ull all=(1ull<<64)-1;
int n;
int S[505],T[505];
ull U[505],V[505];
ull A[505][505];
bool ok=1;
int has[505]; 
vector<int> tmp;
void solve(int bt)
{
	for(int i=0;i<n;i++)has[i]=0;
	
	for(int i=0;i<n;i++)
	{
		if(S[i]==0)
		{
			if((U[i]>>bt&1))
			{
				for(int j=0;j<n;j++)
				{
					A[i][j]|=(1ull<<bt);
					has[j]++;
					if((T[j]==1)&&(!(V[j]>>bt&1)))
					{
						ok=0;
						return;
					}
				}
			}
			else
			{
				int cnt=0;tmp.clear();
				for(int j=0;j<n;j++)
				{
					if((T[j]==0)&&(V[j]>>bt&1))
					{
						A[i][j]|=(1ull<<bt);
						has[j]++;
						cnt++;
					}
					else if((T[j]==1)&&(V[j]>>bt&1)&&(!has[j]))
					{
						tmp.push_back(j);
					}
				}
				if(cnt==n)
				{
					ok=0;
					return;
				}
				if(!tmp.empty())
				{
					while((cnt+(int)tmp.size())>=n)tmp.pop_back();
					for(int j=0;j<tmp.size();j++)
					{
						A[i][tmp[j]]|=(1ull<<bt);
						has[tmp[j]]++;
					}
				}
			}
		}
		else
		{
			if((U[i]>>bt&1))
			{
				bool can=0;
				int may=-1;
				for(int j=0;j<n;j++)
				{
					if((V[j]>>bt&1))
					{
						has[j]++;
						A[i][j]|=(1ull<<bt);
						can=1;
					}
					else if(T[j]==0)
					{
						if(may==-1||(has[j]<has[may]))may=j;
					}
				}
				if(!can)
				{
					if(may==-1)
					{
						ok=0;
						return;
					}
					has[may]++;
					A[i][may]|=(1ull<<bt);
				}
			}
			else
			{
				for(int j=0;j<n;j++)
				{
					if((T[j]==0)&&(V[j]>>bt&1))
					{
						ok=0;
						return;
					}
				}
			}
		}
	}
	for(int j=0;j<n;j++)
	{
		if(T[j]==0)
		{
			if((V[j]>>bt&1))
			{
				if(has[j]!=n)
				{
					ok=0;
					return;
				}
			}
			else
			{
				if(has[j]==n)
				{
					ok=0;
					return;
				}
			}
		}
		else
		{
			if(V[j]>>bt&1)
			{
				if(has[j]==0)
				{
					ok=0;
					return;
				}
			}
			else
			{
				if(has[j]!=0)
				{
					ok=0;
					return;
				}
			}
		}
	}
}
int main()
{
//	cout<<all<<endl;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&T[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%llu",&U[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%llu",&V[i]);
	}
	for(int t=0;t<64;t++)
	{
		solve(t);
		if(!ok)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%llu ",A[i][j]);
		}
		printf("\n");
	}
	return 0;
}