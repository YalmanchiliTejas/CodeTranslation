#include<iostream>
#include<algorithm>
using namespace std;
int n,r,l,a[50];
main()
{
	while(cin>>n>>l>>r,n)
	{
		for(int i=0;i<n;i++)cin>>a[i];
		int cnt=0;
		for(int i=l;i<=r;i++)
		{
			bool flag=n%2;
			for(int j=0;j<n;j++)
			{
				if(i%a[j]<1)
				{
					flag=j%2;
					break;
				}
			}
			cnt+=!flag;
		}
		cout<<cnt<<endl;
	}
}

