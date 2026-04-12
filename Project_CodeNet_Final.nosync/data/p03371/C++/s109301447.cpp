#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
      int a,b,c,x,y,ans=0;
	  cin>>a>>b>>c>>x>>y;
	   int p=abs(x-y);	int k;
	  if ((a+b)>2*c) 
	  {
	  
	  	if (x>y) 
		  {
		  k=x;
	      ans+=p*a;
	   }
	  	else
	  	{
	  		ans+=p*b;
	  	k=y;
	  }
       k=k-p;
	  	ans+=k*2*c;
       k=k+p;
       if (k*c*2<ans) ans=k*c*2;
	  }
	  else
	  {
	  	ans+=(x*a+b*y);
	  }
	  cout<<ans<<endl;
}