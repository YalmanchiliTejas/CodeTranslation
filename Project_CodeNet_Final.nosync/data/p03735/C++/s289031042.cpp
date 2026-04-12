#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<string>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define debug(x) {cout<<(#x)<<" "<<x<<endl;}
using namespace std;
typedef long long LL;

inline int read() {
    int x=0,f=1; char ch=getchar();
    while (!(ch>='0'&&ch<='9')) {if (ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

const int N = 400005;
const int INF = 1000000007;

int n,tot=0;
struct bag{
	int a,b;
} a[N];
LL ans;

bool cmp(bag a,bag b) {
	if (a.a==b.a) return a.b<b.b;
	return a.a<b.a;
}

int main() {

	#ifndef ONLINE_JUDGE
	//	freopen("data.in","r",stdin);
	//	freopen("data.out","w",stdout);
	#endif

	n=read(); rep(i,1,n) a[i]={read(),read()};
	int mxb=0,mxr=0,mnb=INF,mnr=INF;
	rep(i,1,n) {
		int mx=max(a[i].a,a[i].b);
		int mn=min(a[i].a,a[i].b);
		a[i].a=mn,a[i].b=mx;
		mxb=max(mxb,mx); mnb=min(mnb,mx);
		mxr=max(mxr,mn); mnr=min(mnr,mn);
	}
	ans=(LL)(mxb-mnb)*(mxr-mnr);
	
	sort(a+1,a+n+1,cmp);
	int tmp=mxb-mnr;
	mnb=INF; mxb=a[n].a;
	rep(i,1,n-1) {
		mnb=min(mnb,a[i].b);
		mxb=max(mxb,a[i].b);
		ans=min(ans,(LL)tmp*(mxb-min(mnb,a[i+1].a)));
	}
	
	printf("%lld\n",ans);

	return 0;
}
