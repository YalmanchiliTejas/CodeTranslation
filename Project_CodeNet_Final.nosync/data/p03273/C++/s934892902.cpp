//
#include<cstdio>
#include<cmath> 
#include<iostream> 
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;
int m,n,x,a[102];
char c[102][102];
int main()
{
	//freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>c[i][j];
			if(c[i][j]=='#')
				x++;
		}
		if(x==0)
		{
			i--;
			m--;
		}
		x=0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(c[j][i]=='#')
				x++;
		}
		if(x==0)
		{
			a[i]=1;
		}
		x=0;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[j]==0)
				cout<<c[i][j];
		}
		cout<<endl;
	}
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}