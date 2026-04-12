#include <bits/stdc++.h>

using namespace std;

int A[400000],l=100000,r=100000-1,n;
int main()
{
	scanf("%d",&n); for(int i=1;i<=n;i++)
	{
		int k; scanf("%d",&k);
		if(i&1) A[++r]=k;
		else A[--l]=k;
	}
	if(n&1) for(int i=r;i>=l;i--) printf("%d ",A[i]);
	else for(int i=l;i<=r;i++) printf("%d ",A[i]);
	puts(""); return 0;
}