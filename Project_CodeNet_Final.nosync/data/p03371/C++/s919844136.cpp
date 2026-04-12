#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b,c,x,y,maxv,minv,p;
	long long s;
	cin>>a>>b>>c>>x>>y;
	maxv=max(x,y);minv=min(x,y);
	if(minv==x) 
		p=b;
	else
		p=a;
	s=min(a*x+b*y,min(2*maxv*c,2*minv*c+p*int(fabs(x-y))));
	cout<<s<<endl;
	return 0;
}