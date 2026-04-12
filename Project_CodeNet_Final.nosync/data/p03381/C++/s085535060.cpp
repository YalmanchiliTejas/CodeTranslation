#include<cstdio>
#include<algorithm>
#define rg register
#define N 200010
using namespace std;
int n,m,ans[N];
struct rec{
	int pos,val;
}a[N];
inline int read(){
	int k=0,f=1; char c=getchar();
	while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while('0'<=c&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
inline bool cmp(rec a,rec b){
	return a.val<b.val;
}
int main(){
	n=read();
	for(rg int i=1;i<=n;i++) a[i].val=read(),a[i].pos=i;
	sort(a+1,a+1+n,cmp);
	for(rg int i=1;i<=n/2;i++) ans[a[i].pos]=a[n/2+1].val;
	for(rg int i=n/2+1;i<=n;i++) ans[a[i].pos]=a[n/2].val;
	for(rg int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0; 
} 