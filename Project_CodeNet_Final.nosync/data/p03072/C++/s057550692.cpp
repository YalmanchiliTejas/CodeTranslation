#include<stdio.h>
#include<algorithm> 
#define PI 3.1415927
//using namespace std;
int a[105];
int main()
{
	int n,ans=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)  scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int flast=1;
		for(int j=0;j<i;j++) 
		{
			if(a[i]<a[j])
			{
				 flast=0;
				 break;
			}
		}
		if(flast)  ans++;
	}
	printf("%d\n",ans);
	return 0;
}