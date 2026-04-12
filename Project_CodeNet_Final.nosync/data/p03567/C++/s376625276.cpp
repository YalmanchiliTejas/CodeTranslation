#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a,b="A";
	int pos=0;
	cin>>a;
	a=a+"D";
	while(1)
	{
		pos=a.find(b,pos);
		if(pos<0)
		{
			cout<<"No"<<endl;
			break;
		}
		if(a[pos+1]=='C')
		{
			cout<<"Yes"<<endl;
			break;
		}
		pos++;
	}
	return 0;
}