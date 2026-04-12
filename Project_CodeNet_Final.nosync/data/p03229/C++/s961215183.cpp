#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100005;
int b[maxn],a[maxn],n,vis[maxn],v[2];
ll ans;
void calc(){
	int mid=n/2,l=1,r=n,L,R,fg=0,tmp=0,lt=1;
	b[mid]=a[l++];L=mid,R=mid;
	while(l<=r){
		if(fg==0) b[++R]=lt==0?a[l++]:a[r--],lt^=1;
		else b[--L]=lt==0?a[l++]:a[r--],lt^=1;
		if(++tmp==2)fg^=1,tmp=0;
	}
	ll t=0;
	for(int i=L+1;i<=R;i++)t+=abs(b[i]-b[i-1]);
	ans=max(ans,t);
}
inline int read(){
	int x=0;bool f=1;char ch=getchar();
	while (!isdigit(ch)){if(ch=='-')f=0;ch=getchar();}
	while (isdigit(ch))x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	if (f) return x;return -x;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	if(n<=2){printf("%d\n",a[2]-a[1]);return 0;}
	calc();reverse(a+1,a+n+1);calc();
	printf("%lld\n",ans);
	return 0;
}