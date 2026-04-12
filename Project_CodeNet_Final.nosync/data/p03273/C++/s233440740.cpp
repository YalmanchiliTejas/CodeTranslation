#include <iostream>
#include <cstdio>

using namespace std;

int n,m;
char w[108][108];
bool h[108],l[108];

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=m;k++)
		{
			cin>>w[i][k];
			if(w[i][k]=='#')
			{
				h[i]=true;
				l[k]=true;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=m;k++)
		{
			if(h[i]==true && l[k]==true)
			{
				cout<<w[i][k];
			}
		}
		if(h[i]==true)
		{
			cout<<endl;
		}
	}

	return 0;
}

/**
 *      ┌─┐       ┌─┐
 *   ┌──┘ ┴───────┘ ┴──┐
 *   │                 │
 *   │       ───       │
 *   │  ─┬┘       └┬─  │
 *   │                 │
 *   │       ─┴─       │
 *   │                 │
 *   └───┐         ┌───┘
 *       │         │
 *       │         │
 *       │         │
 *       │         └──────────────┐
 *       │                        │
 *       │                        ├─┐
 *       │                        ┌─┘
 *       │                        │
 *       └─┐  ┐  ┌───────┬──┐  ┌──┘
 *         │ ─┤ ─┤       │ ─┤ ─┤
 *         └──┴──┘       └──┴──┘
 */