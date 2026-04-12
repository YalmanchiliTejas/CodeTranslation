#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,x,y,k,m,n;
	cin>>a>>b>>c>>x>>y;
	if(2*c<(a+b))
	{
		if(x>y)
		{
			m=2*y*c+(x-y)*a;
			n=2*x*c;
			if(m<n) k=m;
	            else k=n;
		}    
		if(x==y)   k=2*x*c;
		if(x<y)
		{
			m=2*x*c+(y-x)*b;
			n=2*y*c;
			if(m<n) k=m;
			    else k=n;
		}    
	}
	if(2*c>=(a+b))   k=a*x+b*y;
	cout<<k<<endl;
	return 0;
}