#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	c*=2;
	int ans[5]={0};
	ans[0]=a*x+b*y;
	if(x<y)
	{
		ans[1]=c*x+b*(y-x);
		ans[2]=c*y;
	}
	else
	{
		ans[1]=c*y+a*(x-y);
		ans[2]=c*x;
	}
	ans[3]=c*x+b*y;
	ans[4]=a*x+c*y;
	sort(ans,ans+5);
	cout<<ans[0]<<endl;
	return 0;
}