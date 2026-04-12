#include<iostream>
using namespace std;
int main()
{
	int n,a,b,c,x,i;
	int y[100];
	int flame;
	for(;;)
	{
		cin >> n >> a >> b >> c >> x ;
		if(n==0 && a==0 && b==0 && c==0 && x==0)
			break;
		for(i=0;i<n;i++)
		{
			cin >> y[i] ;
		}
		flame=0;
		int f=1;
		for(i=0;;)
		{
			if(flame==10001)
			{
				f=0;
				break;
			}
			if(y[i]==x)
			{
				i++;
				x=(a*x+b)%c;
				if(i==n)
					break;
				flame++;
			}
			else
			{
				flame++;
				x=(a*x+b)%c;
			}
		}
		if(f==1)
			cout << flame << endl;
		else
			cout << "-1" << endl;
	}
}