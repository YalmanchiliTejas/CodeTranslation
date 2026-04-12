#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c,x,y,max,min=0;
	cin >>a>>b>>c>>x>>y;
	max=x*2;
	if (x<y)
	max=y*2;
	for (int i=0;i<=max;i=i+2)
	{
		int sum,numa,numb;
		numa=x-i/2;
		if (numa<0)
		numa=0;
		numb=y-i/2;
		if (numb<0)
		numb=0;
		sum=i*c+a*numa+b*numb;
		if (sum<min||min==0)
		min=sum;
	}
	cout<<min;
	return 0;
} 