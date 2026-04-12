#include<iostream>
#include<algorithm>
using namespace std;
long long ttt(long long n,long long x,long long *arr,long long *brr)
{
	if(x<=n)		//提前结束并不会使下面循环x<=0 
	{
		return 0;	
	}
	if(n==1)
	{
		if(x==1)
		{
			return 0;
		}
		else if(x==2)
		{
			return 1;
		}
		else if(x==3)
		{
			return 2;
		}
		else
		{
			return 3;
		}
		if(x==5)
		{
			return 3;
		}
	}
	if(n==0)
	{
		return 1;
	 } 
	 if(x==arr[n])
	 {
	 	return brr[n];
	 }
	while(1)
	{
		if(arr[n]/2==x)
		{
			return brr[n-1];
		}
		else if(arr[n]/2>x)
		{
			n--;
			x--;
		}
		else
		{
			break;
		}
	}
	long long sum=brr[n-1]+ttt(n-1,x-arr[n-1]-2,arr,brr)+1;//加中间那个肉片 
	return sum;
	
}
int main()
{
	long long n,x;
	cin>>n>>x;
	long long arr[51];
	long long brr[51];
	brr[0]=1;
	arr[0]=1;
	for(int i=1;i<=n;i++)
	{
		arr[i]=arr[i-1]*2+3;
		brr[i]=brr[i-1]*2+1;
	}
	long long sum=ttt(n,x,arr,brr);
	cout<<sum;
}