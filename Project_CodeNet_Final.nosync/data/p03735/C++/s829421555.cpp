#include<bits/stdc++.h>
#define INF 0x7fffffff
#define P pair<int,int>
#define ll long long
#define f first
#define s second
using namespace std;
int n,nn,nx,mx=-INF,mn=INF;
P a[200005];
ll ans;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
int main(){
    n=read();
    for(int i=1;i<=n;++i){
        a[i].f=read(),a[i].s=read();
        if(a[i].f>a[i].s) swap(a[i].f,a[i].s);
        mx=max(mx,a[i].s),mn=min(mn,a[i].s);
    }
    sort(a+1,a+n+1);
    ans=1ll*(mx-mn)*(a[n].f-a[1].f),nn=nx=a[1].s;
    for(int i=2;i<=n;++i){
        ans=min(ans,1ll*(mx-a[1].f)*(max(nx,a[n].f)-min(nn,a[i].f)));
        nn=min(nn,a[i].s),nx=max(nx,a[i].s);
    }
    printf("%lld",ans);
}