#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	string str;
	
	cin >> N >> str;
	
	string ans[4];
	string end[4];
	
	ans[0]="S";end[0]="S";
	ans[1]="S";end[1]="W";
	ans[2]="W";end[2]="S";
	ans[3]="W";end[3]="W";
	
	for(int i=0;i<N-2;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(i==0)
			{
				if((ans[j][i]=='S' && str[i]=='o') || (ans[j][i]=='W' && str[i]=='x'))
					ans[j]+=end[j];
				else if(end[j][0]=='S')
					ans[j]+="W";
				else
					ans[j]+="S";
			}
			else
			{
				if((ans[j][i]=='S' && str[i]=='o') || (ans[j][i]=='W' && str[i]=='x'))
					ans[j]+=ans[j][i-1];
				else if(ans[j][i-1]=='S')
					ans[j]+="W";
				else
					ans[j]+="S";
			}
		}
	}
	
	for(int i=0;i<4;i++)
	{
		ans[i]+=end[i];
		ans[i]+=ans[i][0];
		ans[i]=end[i]+ans[i];
	}
		
	
	for(int i=0;i<4;i++)
	{
		bool isok=true;
		for(int j=1;j<ans[i].size()-1;j++)
		{
			if((ans[i][j]=='S' && str[j-1]=='o') || (ans[i][j]=='W' && str[j-1]=='x'))
			{
				if(ans[i][j-1]!=ans[i][j+1])
				{
					isok=false;
					break;
				}
			}
			else
			{
				if(ans[i][j-1]==ans[i][j+1])
				{
					isok=false;
					break;
				}
			}
		}
		if(isok)
		{
			for(int j=1;j<ans[i].size()-1;j++)
				cout << ans[i][j];
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
