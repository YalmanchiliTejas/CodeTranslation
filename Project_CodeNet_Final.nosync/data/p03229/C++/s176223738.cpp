#include<stdio.h>
#include<algorithm>
 
#define ll long long int
 
using namespace std;
 
int arr[100005];
 
int main(void)
{
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	ll ans = 0;
	if(n%2==0)
	{
		for(int i=0;i<(n/2)-1;i++)
			ans += 2*arr[n-1-i];
		for(int i=0;i<(n/2)-1;i++)
			ans -= 2*arr[i];
		ans += (arr[(n/2)]-arr[(n/2)-1]);	
	}
	else
	{
		ll t1=0; 
		for(int i=0;i<(n/2);i++)
			t1 += 2*arr[n-1-i];
		for(int i=0;i<(n/2)-1;i++)
			t1 -= 2*arr[i];
		t1 -= (arr[(n/2)-1]+arr[n/2]);
		ll t2=0;
		for(int i=0;i<(n/2)-1;i++)
			t2 += 2*arr[n-1-i];
		for(int i=0;i<(n/2);i++)
			t2 -= 2*arr[i];
		t2 += arr[n/2]+arr[n/2+1];
		
		ans = t1<t2 ? t2:t1;		
	}
	printf("%lld",ans);		
	return 0;
}