#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,x,y,maxn,minn;
	cin>>a>>b>>c>>x>>y;
	if(x>y) minn=y,maxn=x;
	else minn=x,maxn=y;
	int sum[maxn+2];
	sum[0]=x*a+y*b;
	for(int i=1;i<=minn;i++)
		sum[i]=2*i*c+(y-i)*b+(x-i)*a;
	for(int i=minn+1;i<=maxn;i++)
		if(y>x) sum[i]=2*i*c+(y-i)*b;
		else sum[i]=2*i*c+(x-i)*a;
	sort(sum,sum+maxn+1);
	cout<<sum[0];
	return 0;
}