#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=2e5+5,inf=1e9;
int n,i,mn,mx;ll ans;
struct arr{int x,y;}a[N];
bool operator < (arr A,arr B){return A.x<B.x;}
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
int main(){
	for (n=read(),mn=1e9,i=1;i<=n;i++){
		int x=read(),y=read();
		if (x<y) swap(x,y);
		mn=min(mn,x);mx=max(mx,x);
		a[i]=(arr){y,x};
	}
	sort(a+1,a+n+1);a[0].x=inf;
	ans=(ll)(mx-mn)*(a[n].x-a[1].x);
	int v=(mx-a[1].x);mn=inf;mx=0;
	for (i=1;i<=n&&a[i].x<mn;i++){
		mn=min(mn,a[i].y);mx=max(mx,a[i].y);
		ans=min(ans,(ll)v*(max(a[n].x,mx)-min(mn,a[i+1].x)));
	}
	printf("%lld",ans);
}