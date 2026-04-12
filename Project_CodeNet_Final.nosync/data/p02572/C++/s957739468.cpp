#include <cstdio>
#include <cstdlib>

using namespace std;

const int N=200010,mo=1000000007;
int n,a[N];
long long sum[N],ans;

inline void re(int &x)
{
	x=0;
	bool flag=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') flag|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=flag ? -x : x;
}

int main()
{
    int i;
    re(n);
    for(i=1;i<=n;i++) re(a[i]);
    for(i=n;i>1;i--) sum[i]=(sum[i+1]+a[i])%mo;
    for(i=1;i<n;i++) ans=(ans+(a[i]*sum[i+1])%mo)%mo;
    printf("%lld",ans);
    return 0;
}