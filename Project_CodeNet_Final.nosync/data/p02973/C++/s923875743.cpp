#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
#define Maxn 200010
int a[Maxn];
int b[Maxn],l,r;
int main(){
	int ans=1;
	scanf("%d",&n);
	l=r=n;
	scanf("%d",&a[1]);
	b[n]=a[1];
	for(register int i=2;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]<=b[l]){
			l--;
			b[l]=a[i];
			ans++;
			continue;
		}
		int L=l,R=r;
		while(L<R){
			int mid=(L+R)>>1;
			if(b[mid+1]<a[i])L=mid+1;
			else R=mid;
		}
		b[L]=a[i];
	}
	printf("%d\n",ans);
	return 0;
}