#include<bits/stdc++.h>
using namespace std;
int h,w,t;
char a[101][101];
string ans[101];
int main()
{
	cin>>h>>w;
	for (int i=1;i<=h;i++) for (int j=1;j<=w;j++) cin>>a[i][j];
	for (int i=1;i<=h;i++)
	{
		bool frow=true;
		for (int j=1;j<=w;j++) if (a[i][j]!='.' && a[i][j]!='@') {frow=false; break;}
		if (frow) for (int j=1;j<=w;j++) a[i][j]='@';
	}
	for (int i=1;i<=w;i++)
	{
		bool fcol=true;
		for (int j=1;j<=h;j++) if (a[j][i]!='.' && a[j][i]!='@') {fcol=false; break;}
		if (fcol) for (int j=1;j<=h;j++) a[j][i]='@';
	}
	for (int i=1;i<=h;i++)
	{
		for (int j=1;j<=w;j++)
			if (a[i][j]!='@') ans[t]+=a[i][j];
			//cout<<a[i][j];
		if (ans[t].size()) cout<<ans[t]<<endl,t++;
	}
	
    return 0;
}