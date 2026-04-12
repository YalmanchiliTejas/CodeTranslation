#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,num=0;
	cin>>a>>b>>c;
	b=b+c;
	a-=(b+c);
	while(a>=0)
	{
		a-=b;
		num++;
	}
	if(num<0)
	{
		cout<<0<<endl;
		return 0;
	}
	cout<<num<<endl;
	return 0;
}