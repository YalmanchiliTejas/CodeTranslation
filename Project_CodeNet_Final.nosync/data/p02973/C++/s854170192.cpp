#include <bits/stdc++.h>

using namespace std;

int n,len,ans,bj[100010];
long long int num[100010],lisan[100010];

int cmp1(long long int a,long long int b)
{
	return a<b;
}

long long int search(long long int x)
{
	long long int l=1,r=n;
	while(l+1<r)
	{
		long long int mid=(l+r)/2;
		if(x>lisan[mid])
		    l=mid;
		else
		    r=mid;
	}
	long long int mid=(l+r)/2;
	if(x>lisan[mid])
		l=mid;
	else
	    r=mid;
	return r;
}


int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	    scanf("%lld",&num[i]);
		lisan[i]=num[i];	
	}    
	sort(lisan+1,lisan+n+1,cmp1);
	for(int i=1;i<=n;i++)
		num[i]=search(num[i]);
	for(int i=1;i<=n;i++)
	{
		if(len==0)
		{
			len++;
			bj[len]=num[i];
		}
		else
		{
			int l=1,r=len;
        	while(l+1<r)
	        {
		        long long int mid=(l+r)/2;
		        if(num[i]>bj[mid])
		            r=mid;
		        else
		            l=mid;
	        }
	        long long int mid=(l+r)/2;
	        if(num[i]>bj[mid])
		        r=mid;
	        else
	            l=mid;
	        if(bj[r]>=num[i])
	        {
	        	len++;
	        	bj[len]=num[i];
			}
			else
			{
				bj[r]=num[i];
			}
			    
		}
		
	}
	printf("%d\n",len);
	return 0;
} 