#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,y,s,b1,s1,s2,s3;
int minn=2100000000;
char ss,bb;
int main()
{
	cin>>a>>b>>c>>x>>y;
	s1=a*x+b*y;
	if(x>y)
	{
		bb='A';
		ss='B';
		b1=x;
		s=y;
	}
	else
	{
		bb='B';
		ss='A';
		s=x;
		b1=y;
	}
	if(bb=='B')
		s2=c*x*2+(y-x)*b;
	else s2=c*y*2+(x-y)*a;
	int maxn=max(x,y);
	s3=c*maxn*2;
	minn=min(s1,s2);
	minn=min(minn,s3);
	cout<<minn<<endl;
	return 0;
}