#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;


int main()
{
	int ans=0;
	int x,y,z;
	cin>>x>>y>>z;
	while(x>z+y)
	{
		x-=z+y;
		if(x>=z) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
