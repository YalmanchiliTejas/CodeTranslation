#include <bits/stdc++.h>
using namespace std;

long long x,y,z;
int main()
{
	cin>>x>>y>>z;
	for(int i=0;i<=100000;i++)
	{
		if(y*i+(i+1)*z<=x)
		{
			if(y*(i+1)+(i+2)*z>x)
			cout<<i;
		}
    }
    return 0;
}