#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

deque<int> x;

const int Q=300007;

int v[Q];

int main()
{
	//freopen("data.in","r",stdin);
	int dir=1;

	int n;
	cin>>n;

	int r;

	for(int i=1; i<=n; i++)
	{
		cin>>r;
		if(dir==1)
		{
			x.push_back(r);
			dir=2;
		}
		else
		{
			x.push_front(r);
			dir=1;
		}
	}	

		for(auto it:x)
		{
			v[++v[0]]=it;
		}

	if(dir==1)
	{
		for(int i=1; i<=n; i++)
		{
			cout<<v[i]<<" ";
		}
	}
	else
	{
		for(int i=n; i>0; i--)
		{
			cout<<v[i]<<" ";
		}
	}




}