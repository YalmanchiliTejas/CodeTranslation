#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,len;
int a[100005],f[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[++len]=a[1];
	for(int i=2;i<=n;i++){
		if(f[len]>=a[i]) f[++len]=a[i];
		else{
			int l=1,r=len;
			while(l<=r){
				int mid=(l+r)>>1; 
				if(f[mid]>=a[i]) l=mid+1;
				else r=mid-1;
			} 
			f[l]=max(f[l],a[i]);
		}
	}
	printf("%d",len);
	return 0;
} 