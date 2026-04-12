#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
int main() {
	static int n,a[200005],b[200005];
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i);
	if(n&1) {
		b[n/2+1]=a[1];
		int cnt=1;
		rep(i,1,n/2)
			b[n/2+i+1]=a[++cnt],
			b[n/2-i+1]=a[++cnt];
	}
	else {
		b[n/2+1]=a[1];
		int cnt=1;
		rep(i,1,n/2) {
			b[n/2+1-i]=a[++cnt];
			if(i!=n/2) b[n/2+1+i]=a[++cnt];
		}
	}
	rep(i,1,n-1) printf("%d ",b[i]);
	printf("%d\n",b[n]);
	return 0;
}