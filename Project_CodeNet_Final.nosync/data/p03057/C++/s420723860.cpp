#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long ll;

const int N=2e5+5,Mo=1e9+7;

int n,m,k,f[N],s[N];
char st[N];

int main() {
	scanf("%d%d",&n,&m);
	scanf("%s",st+1);
	k=1;for(;k<m&&st[k+1]==st[1];k++);
	if (k==m) {
		f[0]=s[0]=1;
		fo(i,1,n) {
			if (i>=2) f[i]=s[i-2];
			s[i]=(s[i-1]+f[i])%Mo;
		}
		int ans=1;
		fo(i,2,n) (ans+=(ll)i*f[n-i]%Mo)%=Mo;
		printf("%d\n",ans);
		return 0;
	}
	if (n&1) {puts("0");return 0;}
	int lim=k+1,now=0;
	for(k++;k<=m;k++) {
		if (st[k]==st[1]) now++;
		else {
			if (now&1) lim=min(lim,now);
			now=0;
		}
	}
	n>>=1;lim=(lim+1)>>1;
	f[0]=s[0]=1;
	fo(i,1,n) {
		f[i]=s[i-1];
		if (i-lim-1>=0) (f[i]+=Mo-s[i-lim-1])%=Mo;
		s[i]=(s[i-1]+f[i])%Mo;
	}
	int ans=0;
	fo(i,1,lim) (ans+=(ll)(i<<1)*f[n-i]%Mo)%=Mo;
	printf("%d\n",ans);
	return 0;
}