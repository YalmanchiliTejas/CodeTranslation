#include<bits/stdc++.h>
#define ll long long
#define N 200002
#define inf 2147483647
using namespace std;
inline int read(){
    int x=0; bool f=1; char c=getchar();
    for(;!isdigit(c); c=getchar()) if(c=='-') f=0;
    for(; isdigit(c); c=getchar()) x=(x<<3)+(x<<1)+(c^'0');
    if(f) return x;
    return 0-x;
}
int n; ll ans;
struct num{int x,y,id;}s[N<<1];
inline bool cmp(num a, num b){return a.x<b.x;}
int main(){
    n=read();
    int a,b, lmin=inf, lmax=0, rmin=inf, rmax=0, minx, maxx;
    for(int i=1; i<=n; ++i){
        a=read(), b=read(); if(a>b) swap(a,b);
        s[i]=(num){a,b,i};
        if(a<lmin) lmin=a, minx=i; lmax=max(lmax,a);
        rmin=min(rmin,b); if(b>rmax) rmax=b, maxx=i;
    }
    ans = (ll)(lmax-lmin) * (rmax-rmin);
     
    if(minx!=maxx){
        sort(s+1,s+n+1,cmp);
        int mx=s[1].y, mn=mx, tmp=s[n].x-s[1].x;
        for(int i=1; i<=n; ++i){
            mx=max(mx,s[i].y), mn=min(mn,s[i].y);
            tmp = min(tmp, max(mx,s[n].x)-min(mn,s[i+1].x));
        }
        ans = min(ans, (ll)tmp*(rmax-lmin));
    }
    cout<<ans<<endl;
    return 0;
}