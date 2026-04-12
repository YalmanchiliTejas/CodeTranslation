#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	if(a+b<=2*c)
		cout<<a*x+b*y;
	else if(x>y)
		cout<<min(2*y*c+a*(x-y),2*c*max(x,y));
	else
		cout<<min(2*x*c+b*(y-x),2*c*max(x,y));
	return 0;
}