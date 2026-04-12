#include <bits/stdc++.h>
using namespace std; 
int main()
{
	int a,h=0,sum=0,n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a>=sum)
		{
			sum=a;
			h++;
		}
	}
	cout<<h<<endl;
	return 0;
}