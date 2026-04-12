#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
bool v[N];
int n,m,x,y,c[N],q[N],t,X;
vector<int>a[N];
int main()
{
	cin>>n;
	m=n-1;
	while(m--&&cin>>x>>y)
		a[x].push_back(y),a[y].push_back(x),c[x]++,c[y]++;
	for(int i=1;i<=n;i++)
		if(c[i]==1)
			q[++t]=i;
	while(t)
	{
		X=q[t--];
		if(v[X])
			continue;
		for(int i=0;i<a[X].size();i++)
			if(!v[a[X][i]])
			{
				v[X]=v[a[X][i]]=true;
				for(int j=0;j<a[a[X][i]].size();j++)
					if(!v[a[a[X][i]][j]])
					{
						c[a[a[X][i]][j]]--;
						if(c[a[a[X][i]][j]]==1)
							q[++t]=a[a[X][i]][j];
					}
			}
		if(!v[X])
		{
			cout<<"First";
			return 0;
		}
	}
	cout<<"Second";
	return 0;
}