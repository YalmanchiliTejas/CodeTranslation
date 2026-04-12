#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;
 int main()
 {
 	long long int a,b,c,x,y,sum,xymin;
 	cin>>a>>b>>c>>x>>y;
	 	sum=0;
 		if(a+b<c*2)
 		{
 			sum=x*a+y*b;
		}
		else
		{
		  	if(x>y)
 		   {
 		   	xymin=y;
			if(a>(c*2))
 				sum+=(x-y)*c*2;
 				else
 					sum+=(x-y)*a;
		   }
		 	else if(x<y)
		 	{
		 		xymin=x;
				if(b>(c*2))
 				sum+=(y-x)*c*2;
 				else
 					sum+=(y-x)*b;
		 	}
		 	sum+=xymin*c*2;
		} 
		 cout<<sum<<'\n';
 	return 0;
  } 