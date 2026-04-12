#include<iostream>
using namespace std;


int main()
{
	int a,b,c,x,y,s1=0,s2=0,s3=0;
	cin>>a>>b>>c>>x>>y;
	s1+=a*x+b*y;
	if(x>=y)
	{
		s2+=c*2*y;
		s2+=a*(x-y);
	}
	else 
	{
		s2+=c*2*x;
		s2+=b*(y-x);
	}
	s3+=c*max(x,y)*2;
	cout<<min(s1,min(s2,s3));
	
	return 0;
}