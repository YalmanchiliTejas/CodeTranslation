#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
#define lowbit(x) (x& -x)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define inf 0x3f3f3f3f
#define mod 1000000007
#define eps 1e-18
inline ll read()
{
    ll tmp=0; char c=getchar(),f=1;
    for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
    for(;'0'<=c&&c<='9';c=getchar())tmp=(tmp<<3)+(tmp<<1)+c-'0';
    return tmp*f;
}
using namespace std;
struct data{
	int id,k;
}a[200010];
int ans[200010];
int n;
bool cmp(data a,data b){return a.k<b.k;}
int main()
{
	int i;
	n=read();
	for(i=1;i<=n;i++)a[i].k=read(),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
		if(i<=n/2)ans[a[i].id]=a[n/2+1].k;
		else ans[a[i].id]=a[n/2].k;
	for(i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}