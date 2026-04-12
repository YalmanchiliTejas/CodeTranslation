#include<iostream>
using namespace std;
const int MAXN = 100 + 5;
char a[MAXN][MAXN];
bool print[MAXN][MAXN];
int n,m;
int main()
{
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j++)
			cin>>a[i][j];
	for(int i = 1 ; i <= n ; i++)
	{
		bool k = false;
		for(int j = 1 ;j <= m ; j++)
			if(a[i][j] == '#')
				k = true;
		if(!k)
			for(int j = 1 ; j <= m ; j++)
				print[i][j] = true;
	}
	for(int i = 1 ; i <= m ; i++)
	{
		bool k = false;
		for(int j = 1 ;j <= n ; j++)
			if(a[j][i] == '#')
				k = true;
		if(!k)
			for(int j = 1 ; j <= n ; j++)
				print[j][i] = true;
	}	
	for(int i = 1 ; i <=n ; i ++)
	{
		bool out = false;
		for(int j = 1 ; j <= m ;j++)
		{
			
			if(!print[i][j])
				cout<<a[i][j] , out = true;
		}
		if(out)
			cout<<endl;
	}	
}