#include <iostream>
#include<cstdio>
using namespace std;
int f[100010];
int a[100010];
int main() {
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	f[1]=a[1];
	int ans=1;
	for(int i=2;i<=m;i++){
		if(a[i]<=f[ans])  f[++ans]=a[i];
		else{
			int l=1,r=ans;
			while(l<r){
				int mid=(l+r)>>1;
				if(f[mid]>=a[i]) l=mid+1;
				else r=mid;
			}
			f[l]=a[i];
		}
	}

	printf("%d\n",ans);
	return 0;
}
