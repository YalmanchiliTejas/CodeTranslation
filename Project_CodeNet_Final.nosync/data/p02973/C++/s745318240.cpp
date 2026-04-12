#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,s[maxn],top;
int main()
{
	scanf("%d%d",&n,&s[1]);
	top=1;
	for(register int i=2,x;i<=n;i++)
	{
		scanf("%d",&x);
		if(x>s[1])
			s[1]=x;
		else
			if(x<=s[top])
				s[++top]=x;
			else
			{
				int l=1,r=top;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					if(s[mid]>=x)
						l=mid+1;
					else
						r=mid-1;
				}
				s[l]=x;
			}
	}
	printf("%d",top);
	return 0;
}