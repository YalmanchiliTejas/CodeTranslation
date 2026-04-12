// ===================================
//   author: M_sea
//   website: http://m-sea-blog.com/
// ===================================
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define re register
using namespace std;
typedef long long ll;

inline int read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}

const int N=200000+10;

int n;
struct data { int x,y; } a[N];
bool operator <(data a,data b) { return a.x<b.x; }

inline ll calc1() {
    int rmin=2e9,rmax=0,bmin=2e9,bmax=0;
    for (re int i=1;i<=n;++i) {
        rmin=min(rmin,a[i].x),rmax=max(rmax,a[i].x);
        bmin=min(bmin,a[i].y),bmax=max(bmax,a[i].y);
    }
    return 1ll*(rmax-rmin)*(bmax-bmin);
}

int miny[N],maxy[N];
inline ll calc2() {
    sort(a+1,a+n+1);
    int bmin=2e9,bmax=0;
    for (re int i=1;i<=n;++i)
        bmin=min(bmin,min(a[i].x,a[i].y)),bmax=max(bmax,a[i].y);
    miny[0]=2e9,maxy[0]=0; int ans=2e9;
    for (re int i=1;i<n;++i) {
        miny[i]=min(miny[i-1],a[i].y),maxy[i]=max(maxy[i-1],a[i].y);
        int rmin=min(a[i+1].x,miny[i]),rmax=max(a[n].x,maxy[i]);
        ans=min(ans,rmax-rmin);
    }
    return 1ll*ans*(bmax-bmin);
}

int main() {
    n=read();
    for (re int i=1;i<=n;++i) {
        a[i]=(data){read(),read()};
        if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
    }
    printf("%lld\n",min(calc1(),calc2()));
    return 0;
}
