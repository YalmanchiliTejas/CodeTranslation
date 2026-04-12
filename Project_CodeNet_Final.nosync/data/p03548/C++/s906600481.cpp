#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
int main()
{
	int x,y,z,m,k,l,i=0;
	while(cin>>x>>y>>z)
	{
		m=y+z;
		k=x/m;
		l=x%m;
		if(l<z)
			cout<<k-1<<endl;
		else
			cout<<k<<endl;
	}
}