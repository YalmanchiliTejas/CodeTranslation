#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+10;

int n,a[N];
ll f[N],s[N];

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		s[i]=(i>1?s[i-2]:0)+a[i];
	}
	for(int i=2;i<=n;i++)
		if(i&1) f[i]=max(f[i-1],f[i-2]+a[i]);
		else f[i]=max(s[i-1],f[i-2]+a[i]);
	printf("%lld\n",f[n]);return 0;
}
