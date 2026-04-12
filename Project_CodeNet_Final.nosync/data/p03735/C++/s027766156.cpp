#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
const int maxn=200010,INF=0x3f3f3f3f;
template <typename Tp> inline int getmin(Tp &x,Tp y){return y<x?x=y,1:0;}
template <typename Tp> inline int getmax(Tp &x,Tp y){return y>x?x=y,1:0;}
template <typename Tp> inline void read(Tp &x)
{
    x=0;int f=0;char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') f=1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    if(f) x=-x;
}
struct data{
	int x,y;
	bool operator < (const data &b)const{return x<b.x;}
}a[maxn];
int n,mx,mxp,mn,bmn=INF;
ll ans;
multiset<int> A,B;
int main()
{
	read(n);
	if(n==1){puts("0");return 0;}
	for(int i=1;i<=n;i++)
	{
		read(a[i].x);read(a[i].y);
		if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
		getmax(mx,a[i].y);getmin(bmn,a[i].y);
		A.insert(a[i].x);B.insert(a[i].y);
	}
	sort(a+1,a+n+1);
	mn=a[1].x;ans=(ll)(mx-bmn)*(a[n].x-mn);
	for(int i=2;i<=n;i++) if(a[i].y==mx){mxp=i;break;}
	for(int i=1;i<=n;i++)
	{
		A.erase(A.find(a[i].x));
		B.insert(a[i].x);
		B.erase(B.find(a[i].y));
		A.insert(a[i].y);
	  	getmin(ans,(ll)(*A.rbegin()-*A.begin())*(*B.rbegin()-*B.begin()));
	}
	printf("%lld\n",ans);
	return 0;
}