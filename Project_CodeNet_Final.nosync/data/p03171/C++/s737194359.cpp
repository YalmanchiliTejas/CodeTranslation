#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=3005;
int a[N],n;
ll f[N][N];

ll dp(int l,int r) {
	if(l>r) return 0;
	if(f[l][r]!=-4557430888798830400ll) return f[l][r];
	if(((l+r)&1)==((n+1)&1)) {
		f[l][r]=max(dp(l,r-1)+a[r],dp(l+1,r)+a[l]);
	}
	else {
		f[l][r]=min(dp(l,r-1)-a[r],dp(l+1,r)-a[l]);
	}
	return f[l][r];
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	memset(f,192,sizeof(f));
	printf("%lld\n",dp(1,n));
	
	return 0;
}
