#include<iostream>
#include<string>

using namespace std;

int main()
{
	int h,w;
	cin >> h >> w;
	string s[10];
	for(int i=1;i<=h;i++)
		cin >> s[i-1];
	
	bool can=true;
	int count=0;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(s[i-1][j-1]=='#')
			{
				if(count==j or count+1==j)
					count=j;
				else can=false;
			}
		}
	}
	cout << (can==true ? "Possible" : "Impossible") << endl;
}
