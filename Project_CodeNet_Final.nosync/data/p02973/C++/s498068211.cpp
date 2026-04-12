#include <cstdio>
int f[1000001],a[1000001];
int main()
{
	int ans=0,n=0;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)	scanf("%d",&a[i]);
	f[0]=-1,ans=0;
	for(int i=n;i>=1;--i){
		if(f[ans]<=a[i])	f[++ans]=a[i];
		else{
			int l=0,r=ans;
			while(l<r){
				int mid=(l+r)/2;
				if(f[mid]>a[i])	r=mid;
				else	l=mid+1;
			}
			f[l]=a[i];
		}
	}
	printf("%d",ans);
	return 0;
}