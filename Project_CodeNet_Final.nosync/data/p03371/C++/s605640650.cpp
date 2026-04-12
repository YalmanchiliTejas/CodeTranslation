#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	int n;
	int ab=min(a,2*c),bb=min(b,2*c),cc=min(a+b,2*c),h=min(x,y);
	n=cc*h;
	if(x>y)
	n+=ab*(x-y);
	if(x<y)
	n+=bb*(y-x);
	cout<<n;
	return 0;
}