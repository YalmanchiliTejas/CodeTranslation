/*
本宝的程序外人别想看！！

name: [夏宝宝]
run time：[] ms
compilation time: [] ms
output memory: [] MiB
where: []
state: []
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	
	cout.sync_with_stdio(false);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	char a[4];
	
	a[1]=getchar();
	a[2]=getchar();
	a[3]=getchar();
	
	bool b[3]={false};
	
	for(int i=1; i<=3; i++)
	{
		if(a[i]=='A')
		{
			b[1]=true;
		}
		else if(a[i]=='B')
		{
			b[2]=true;
		}
	}
	
	if(b[1]==true && b[2]==true)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	
	return 0;
}
