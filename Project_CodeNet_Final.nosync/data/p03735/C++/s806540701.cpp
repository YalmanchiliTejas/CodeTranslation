#include<bits/stdc++.h>
using namespace std;
#define Set(a,b) memset(a,b,sizeof(a))
template<class T>inline void init(T&x){
	x=0;char ch=getchar();bool t=0;
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') t=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch-48);
	if(t) x=-x;return;
}typedef long long ll;
const int N=2e5+10;
const int INF=1e9;
int n;
struct ball{int x,y;inline bool operator <(const ball b)const{return x<b.x;}}A[N];
int main()
{
	init(n);ll ans=0;
	int lmin=INF,rmin=INF,lmax=0,rmax=0;
	for(int i=1;i<=n;++i) {
		int x,y;init(x),init(y);
		if(x>y) swap(x,y);
		A[i].x=x,A[i].y=y;
		lmin=min(lmin,A[i].x);
		lmax=max(lmax,A[i].x);
		rmin=min(rmin,A[i].y);
		rmax=max(rmax,A[i].y);
	}ans=(ll)(rmax-rmin)*(lmax-lmin);
	sort(A+1,A+1+n);rmin=lmin;
	int mi,mx;mi=mx=A[1].y;
	int mind=INF;
	for(int i=2;i<=n;++i) {
		mi=min(mi,A[i].y);mx=max(mx,A[i].y);
		if(i<n) mind=min(mind,max(mx,A[n].x)-min(mi,A[i+1].x));
		else    mind=min(mind,mx-mi);
	}
	ans=min(ans,(ll)mind*(rmax-rmin));
	cout<<ans<<endl;
	return 0;
}
