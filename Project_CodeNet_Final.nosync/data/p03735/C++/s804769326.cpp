#include<bits/stdc++.h>
using namespace std;
#define N 1111116

int n,xmx,xmn,ymx,ymn,tmx,tmn;

struct ball{int x,y;}a[N];
bool operator <(ball a,ball b){
	return a.x<b.x;
}

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	n=read();
	xmx=ymx=-1e9;xmn=ymn=1e9;
	for (int i=1;i<=n;i++){
		a[i].x=read();a[i].y=read();
		if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
		xmx=max(xmx,a[i].x);
		xmn=min(xmn,a[i].x);
		ymx=max(ymx,a[i].y);
		ymn=min(ymn,a[i].y);
	}
	long long ans=1ll*(xmx-xmn)*(ymx-ymn);
	sort(a+1,a+n+1);tmn=1e9;tmx=xmx;
	for (int i=1;i<=n;i++){
		ans=min(ans,1ll*(ymx-xmn)*(tmx-min(a[i].x,tmn)));
		tmn=min(tmn,a[i].y);tmx=max(tmx,a[i].y);
	}
	printf("%lld\n",ans);
	return 0;
}