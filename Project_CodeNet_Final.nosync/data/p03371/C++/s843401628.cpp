#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,x,y;
	cin>>a>>b>>c;
	cin>>x>>y;
	int ans1=x*a+y*b;
	int ans=ans1;
	for(int i=0;i<=max(x,y);i++)
	{
		int temp=ans1;
		if(x>=i)
			temp-=i*a;
		else
			temp-=x*a;
		if(y>=i)
			temp-=i*b;
		else
			temp-=y*b;
		temp+=2*i*c;
		//cout<<temp<<" "<<ans<<endl;
		ans=min(temp,ans);
	}
	cout<<ans<<endl;
	return 0;
}