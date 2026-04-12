#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	int n,m;
	cin>>n>>m;
	char d[101][101];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>d[i][j];
	int pf;
	for(int i=0;i<n;i++)
	{
		pf=0;
		for(int j=0;j<m;j++)
		{
			int f=0;
			int ff=0;
			for(int a=0;a<n;a++)
			{
				if(d[a][j]!='.')f=1;
			}
			if(f==0)ff=1;
			f=0;
			for(int a=0;a<m;a++)
			{
				if(d[i][a]!='.')
				{
					//cout<<d[i][a];
					f=1;
				}
			}
			if(f==0)pf=1;
			//cout<<endl;
			//cout<<ff<<endl;
			if(f==0)ff=1;
			if(!ff)cout<<d[i][j];
		}
		if(!pf)
		cout<<endl;
	}
	return 0;
}