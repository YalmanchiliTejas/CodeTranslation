#include <map>
#include <list>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int a,b,c,x,y;
int main()
{
	fast; 
	cin>>a>>b>>c>>x>>y;
	if (a+b<=2*c)
	   cout<<a*x+b*y;
	else if (x>y)
	   cout<<min(2*y*c+a*(x-y),2*c*max(x,y));
	else
	   cout<<min(2*x*c+b*(y-x),2*c*max(x,y));
	return 0;
}
