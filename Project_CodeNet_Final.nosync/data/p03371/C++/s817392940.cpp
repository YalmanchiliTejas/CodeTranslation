#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
		long int cost=0;
	if(x>y)
	 {
	 
		 if((a+b)>2*c)
		  cost=2*c*y;
		else
		 cost=(a+b)*y;
		 x=x-y;
		 if(a>2*c)
		  cost+=2*c*x;
		  else
		  cost+=a*x;
		  cout<<cost;
	 }
	 else
	 {
	 	if((a+b)>2*c)
		  cost=2*c*x;
		else
		 cost=(a+b)*x;
		 y=y-x;
		 if(b>2*c)
		  cost+=2*c*y;
		  else
		   cost+=b*y;
		  cout<<cost;
	 	
	 }
}