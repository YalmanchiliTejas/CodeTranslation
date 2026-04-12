#include<bits/stdc++.h>
#define M 100007
using namespace std;
int n,ans=1,a[M],b[M];
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	b[1]=a[n];
	for(int i=n-1; i>=1; i--) {
		if(b[ans]<=a[i])b[++ans]=a[i];
		else {
			int l=1,r=ans;
			while(l<=r){
				int mid=(l+r)>>1;
				if(b[mid]<=a[i])l=mid+1;
				else r=mid-1;
			}b[l]=a[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}