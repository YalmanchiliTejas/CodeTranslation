#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int h,w;
	cin >> h >> w;
	vector<string> g(h);
	for(int i = 0;i<h;i++)cin >> g[i];
	int cnt = 0;
	for(int i = 0;i<h;i++)
	{
		for(int j = 0;j<w;j++)
		{
			if(g[i][j]=='#')
			{
				cnt ++ ;
			}
		}
	}
	if(cnt==h+w-1)
	{
		cout<<"Possible"<<endl;
	}
	else
	{
		cout<<"Impossible"<<endl;
	}
	
	
	return 0;
}