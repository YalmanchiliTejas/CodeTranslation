#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int x,y,z,n;
int main()
{
	cin>>x>>y>>z;
    n=x/(y+z);
    if(x-n*(y+z)<z)
		cout<<n-1<<endl;
		else cout<<n<<endl;
	return 0;
	}