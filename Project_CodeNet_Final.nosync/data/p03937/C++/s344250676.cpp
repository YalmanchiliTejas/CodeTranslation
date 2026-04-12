#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int h,w;
	cin >> h >> w;
	vector<string> s(h);
	for(int i =0;i<h;i++)cin>>s[i];
	int cnt = 0;
	for(auto i:s)
	for(auto j:i)
	{
		if(j=='#')cnt++;
	}
	if(cnt==h+w-1&&s[0][0]=='#'&&s[h-1][w-1]=='#')
	{
		cout<<"Possible"<<endl;
	}
	else
	{
		cout<<"Impossible"<<endl;
	}
	
	return 0;
}