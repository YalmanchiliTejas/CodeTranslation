#include <bits/stdc++.h>
using namespace std;
int main()
{
	string route;
	cin>>route;
	int a=0,b=0,i;
	for(i=0;i<3;i++)
	{
		if(route[i]=='A')
			a++;
		else
			b++;
	}
	if(a==0||b==0)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	return 0;
}
