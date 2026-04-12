#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int h,w;
	cin >> h >> w;
	string map[h];
	
	for(int i=1;i<=h;i++)
		cin >> map[i-1];

	int able[105][105]={};
	
	for(int i=1;i<=h;i++)
	{
		int count=0;
		for(int j=1;j<=w;j++)
		{
			if(map[i-1][j-1]=='.')count++;
			else break;
		}
		if(count==w)
			for(int j=1;j<=w;j++)
				able[i-1][j-1]=1;
	}
	for(int i=1;i<=w;i++)
	{
		int count=0;
		for(int j=1;j<=h;j++)
		{
			if(map[j-1][i-1]=='.')count++;
			else break;
		}
		if(count==h)
			for(int j=1;j<=h;j++)
				able[j-1][i-1]=1;
	}

	for(int i=1;i<=h;i++)
	{
		bool flag=false;
		for(int j=1;j<=w;j++)
		{
			if(able[i-1][j-1]==0)
			{
				flag = true;
				cout << map[i-1][j-1];
			}
		}
		if(flag == true)
			cout << endl;
	}
}



