#include <bits/stdc++.h>
using namespace std;
template<typename T> void rd(T &t) {
	char ch=getchar(); t=0; int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9');
	t*=f;
}
const int maxn=200010;
pair<int,int> a[maxn];
int n,ans[maxn];
int main() {
//	freopen("1.txt","r",stdin);
	rd(n);
	for (int i=1;i<=n;i++) {
		rd(a[i].first); a[i].second=i;
	}
	sort(a+1,a+(n+1));
	for (int i=1;i<=n;i++) {
		if (i<=n/2) ans[a[i].second]=a[n/2+1].first;
		else ans[a[i].second]=a[n/2].first;
	}
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}