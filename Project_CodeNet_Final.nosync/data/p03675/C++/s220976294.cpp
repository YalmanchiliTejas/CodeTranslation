#include<bits/stdc++.h>
using namespace std;
#define M 200005
int n,A[M],B[M];
int main(){
	scanf("%d",&n);
	int l=n/2+1,r=n/2,a;
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		if(i&1)B[++r]=a;
		else B[--l]=a;
	}
	if(n&1)for(int i=r;i>=l;i--)printf("%d ",B[i]);
	else for(int i=l;i<=r;i++)printf("%d ",B[i]);
	return 0;
}