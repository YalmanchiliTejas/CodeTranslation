#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {


	int m = 0;
	int n = 0;
	int i = 0;
	int j = 0;
	int check = 1;
	char origin[150][150];
	
	cin>>m>>n;
	
	for(i=0;i<=m+3;i++)
	{
		for(j=0;j<=n+3;j++)
		{
			origin[i][j] = '1';
		}
	}
	i = 0;
	j = 0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>origin[i][j];
		}
	}
	
	
	
	for(i=0;i<m;i++)
	{
		check = 0;
		if(origin[i][0] == '.')
		{
			
			for(j=0;j<n;j++)
			{
				if(origin[i][j] == '.')
				{
					check = check + 1;
				}
			}
		}
		if(check==n)
		{
			for(j=0;j<n;j++)
			{
				origin[i][j] = '0';
			}
			check = 0;
		}
	}
	
	
	for(i=0;i<n;i++)
	{
		check = 0;
		if((origin[0][i]=='.')||(origin[0][i]=='0'))
		{
			for(j=0;j<m;j++)
			{
				if((origin[j][i]=='.')||(origin[j][i]=='0'))
				{
					check = check + 1;
				}
			}
		}
		if(check==m)
		{
			for(j=0;j<m;j++)
			{
				origin[j][i] = '0';
			}
			check = 0;
		}	
	}
	
	
	
	for(i=0;i<m;i++)
	{
		check = 0;
		if((origin[i][0]=='.')||(origin[i][0]=='0'))
		{
			for(j=0;j<n;j++)
			{
				if((origin[i][j]=='.')||(origin[i][j]=='0'))
				{
					check = check + 1;
				}
				else if(origin[i][j]=='#')
				{
					break;
				}
			}
		}
		
		if(check==n)
		{
			continue;
			check = 0;
		}
		else
		{
			for(j=0;j<n;j++)
			{
				if(origin[i][j]=='0')
				{
				}
				else
				{
					cout<<origin[i][j];
				}
			}
			if(check==n)
			{
				check = 0;
			}
			else
			{
				cout<<endl;
			}

		}
	}

	

}

