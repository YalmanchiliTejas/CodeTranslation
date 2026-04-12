#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<cstdio>
#include<queue>
using namespace std;
const int N=100005;
long long  a[N];
int main()
{

	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n==2) 
	{
		cout<<fabs(a[0]-a[1])<<endl;
		return 0;
	}
	 sort(a,a+n);
	
	 long long ans1=0,ans2=0;
	 
	 	int i=0,j=n-1,k=0;
		while(1)
		{

			ans1+=-2*a[i];
			i++;
			k++;
			if(k>=n-2) break;
			
			ans1+=2*a[j];
			j--;
			k++;  
			if(k>=n-2) break;
		}
		ans1+=a[j];
		if(n%2==0)
			ans1-=a[i];
		else
			ans1+=a[i];
		
		i=0,j=n-1,k=0;
		while(1)
		{
			ans2+=2*a[j];
			j--;
			k++;  
			if(k>=n-2) break;
			
			ans2+=-2*a[i];
			i++;
			k++;
			if(k>=n-2) break;
		}
	    ans2-=a[i];
		if(n%2==0)
			ans2+=a[j];
		else
			ans2-=a[j];
	 
	cout<<max(ans1,ans2)<<endl;
    return 0;
}
