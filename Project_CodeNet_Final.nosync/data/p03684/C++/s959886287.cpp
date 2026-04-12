#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<=(b);++i)
#define ROF(i,a,b) for (int i=(a);i>=(b);--i)
typedef long long ll;
inline int read() {
	int x=0,s=1; char ch=getchar();
	while (ch<'0'||ch>'9') { if (ch=='-') s=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return s*x;
}

const int MAXN=200005,Mo=1000000007;
struct Data{ int x,y,i; }A[MAXN];
vector<pair<int,pair<int,int> > >Q;
int n,m,q,a[MAXN],b[MAXN],c[MAXN],f[MAXN];
int cmp1(Data i,Data j){ return i.x<j.x; }
int cmp2(Data i,Data j){ return i.y<j.y; }
int ask(int x){ if (f[x]==x) return x; return f[x]=ask(f[x]); }
int main(){
	n=read();
	FOR(i,1,n) A[i].x=read(),A[i].y=read(),A[i].i=i;
	sort(A+1,A+1+n,cmp1);
	FOR(i,1,n-1) {
		int x=A[i].i,y=A[i+1].i,z=min(abs(A[i].x-A[i+1].x),abs(A[i].y-A[i+1].y));
		//printf("%d---%d %d\n",x,y,z);
		Q.push_back(make_pair(z,make_pair(x,y)));
	}
	sort(A+1,A+1+n,cmp2);
	FOR(i,1,n-1) {
		int x=A[i].i,y=A[i+1].i,z=min(abs(A[i].x-A[i+1].x),abs(A[i].y-A[i+1].y));
		//printf("%d---%d %d\n",x,y,z);
		Q.push_back(make_pair(z,make_pair(x,y)));
	}
	sort(Q.begin(),Q.end());
	FOR(i,1,n) f[i]=i;
	int size=Q.size();
	ll ans=0;
	FOR(i,0,size-1) {
		pair<int,pair<int,int> > l=Q[i];
		int z=l.first,x=l.second.first,y=l.second.second;
		int X=ask(x),Y=ask(y);
		if (X!=Y) f[X]=Y,ans+=z;
	}
	printf("%lld\n",ans);
	
	return 0;
}

/*
3
1 5
3 9
7 8

*/
