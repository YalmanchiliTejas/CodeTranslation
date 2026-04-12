#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x1,x2,x3,X,Y;
	cin>>x1>>x2>>x3>>X>>Y;
	 int price=0,big=0,maxx;
	 
	 if(X>Y)  maxx=X;
	 else  maxx=Y;
	 
	
	
	 if((x1+x2)/2>=x3)
	   {
	   if(X>Y)  big=Y;
	   else  big=X;
	   price=2*big*x3+price;
	   if(X>Y)  price=price+(X-Y)*x1;
	   else  price=price+(Y-X)*x2;
	   }
	
	if((x1+x2)/2<x3)
	price=x1*X+x2*Y;
	
	if(x3*2*maxx<price)
	price=x3*2*maxx;

	cout<<price<<endl;
	return 0;
}