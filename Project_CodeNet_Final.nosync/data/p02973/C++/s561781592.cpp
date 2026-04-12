#include<bits/stdc++.h>
#define maxn 200010

using namespace std;

int q[maxn],l,a[maxn],n;

int main() {
	int i,x;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n/2;i++) 
		swap(a[n-i+1],a[i]);
	for (i=1;i<=n;i++) {
		if (a[i]>=q[l]) q[++l]=a[i];
		else {
			x=upper_bound(q+1,q+l+1,a[i])-q;
			q[x]=a[i];
		}
	}
	printf("%d\n",l);
	return 0;
}