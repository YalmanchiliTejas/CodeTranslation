#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	int a[200005],temp[200005];
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			temp[i]=a[i];
		}
		sort(a+1,a+n+1);
		int  flag; 
		for(int i=1;i<=n;i++)
		  {
		     flag=temp[i];
		     if(flag<=a[n/2])cout<<a[n/2+1]<<endl;
		     else cout<<a[n/2]<<endl;
		   }
		
	}
}