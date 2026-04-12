#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define		CH		ch=(getchar())

inline		int		IN(){
	int x=0,f=1;char ch;
	for (CH;ch>'9'||ch<'0';CH) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';CH) (x*=10)+=ch-'0';
	return x*f;
}

int i,j,k,l,n,m,p;
long long a[105],Max,ans;

int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (;;){
		Max=0;
		for (i=1;i<=n;i++) if (a[i]>Max){Max=a[i];p=i;}
		if (Max<n){
			printf("%lld",ans);
			return 0;
		}
		ans+=Max/(long long)n;
		for (i=1;i<=n;i++) if (i!=p) a[i]+=Max/(long long)n;
		a[p]%=(long long)n;
	}
}
