#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pint pair<int,int>
#define mk(x,y) make_pair(x,y)
#define fir first
#define sec second
#define Rep(x,y,z) for(int x=y;x<=z;++x)
#define Red(x,y,z) for(int x=y;x>=z;--x)
using namespace std;
char buf[1<<12],*p1=buf,*p2=buf,nc;int ny;
inline char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
//inline char gc(){return getchar();}
inline int read(){
	int x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;if(nc<0)return nc;
	x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48);return x*ny;
}
int main(){
//	freopen("std.in","r",stdin);
//	freopen("std.out","w",stdout);
	if(read()>=30)puts("Yes");
	else puts("No");
	return 0;
}

