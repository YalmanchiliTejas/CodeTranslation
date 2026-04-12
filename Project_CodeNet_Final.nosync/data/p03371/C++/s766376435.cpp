#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	long long int a=0,b=0,c=0,x=0,y=0;
	cin>>a>>b>>c>>x>>y;
	
	long long int sum=0;
	long long int maxn=2*max(x,y);
	long long int minn=0;
	long long int ia=0,ib=0;
	
	for(int i=0;i<=maxn;i+=2)
	{
		ia=x-i/2;
		if(ia<0)
		{
			ia=0;
		}
		
		ib=y-i/2;
		if(ib<0)
		{
			ib=0;
		}
		
		sum=i*c+a*ia+b*ib;
		if(sum<minn||minn==0)
			minn=sum;
	} 
	cout<<minn<<endl;
	return 0;
}

 