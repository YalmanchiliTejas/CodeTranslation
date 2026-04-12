#include<cstdio>
#include<algorithm>
using namespace std;
int n,dl[100005],len,a[100005];
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	len=1;
	dl[1]=a[n];
	for(int i=n-1; i>=1; i--) {
		int k=upper_bound(dl+1,dl+1+len,a[i])-dl;
		if(k>len) dl[++len]=a[i];
		if(dl[k]>a[i]) dl[k]=a[i];
	}
	printf("%d",len);
}
