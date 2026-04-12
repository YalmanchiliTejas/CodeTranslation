// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

ll read() {
	ll X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

const int N=50+10;

int n; ll a[N];

int main() {
	n=read();
	for (int i=1;i<=n;++i) a[i]=read();
	ll ans=0;
	while (1) {
		int p=max_element(a+1,a+n+1)-a;
		if (a[p]<n) break;
		ll c=(a[p]-n)/n+1; ans+=c;
		a[p]-=c*n;
		for (int i=1;i<=n;++i)
			if (i!=p) a[i]+=c;
	}
	printf("%lld\n",ans);
	return 0;
}