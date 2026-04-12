#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z,n;
	cin>>x>>y>>z;x-=z;
	if(x<y+z)cout<<"0"<<endl;
	else cout<<x/(y+z)<<endl;
	return 0;
}