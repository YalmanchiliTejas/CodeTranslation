#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	if((a+b)/2<c)
	   cout<<a*x+b*y; 
	else
	  cout<<min(2*c*min(x,y)+a*(x-min(x,y))+b*(y-min(x,y)),2*c*max(x,y));
	cout<<endl;
	return 0;
}