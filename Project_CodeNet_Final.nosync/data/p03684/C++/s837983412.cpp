#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ls rt<<1
#define rs rt<<1|1
typedef pair<int,int> pii;
const int maxn = 2e5 + 10;
const int maxm = 1e6 + 10 ;
const int inf=0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int st=(1<<20)-1;
const int mod = 1e9+7;
const double eps = 1e-5;
const int vec[2][2]={1,0,0,1};

inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

inline ll sv(ll x) {
    ll ans=1;
    for(int i=1;i<=x;i++) {
        ans*=i;
        ans%=mod;
    }
    return ans;
}

struct node {
    int x,y,id;
}a[maxn];
struct edge{
    int x,y,w;
    bool operator < (const edge &b)const{
        return w<b.w;
    }
}e[maxn<<2];
inline bool cmp1(const node &x,const node &y){
    return x.x<y.x;
}
inline bool cmp2(const node &x,const node &y){
    return x.y<y.y;
}
int f[maxn];
inline int fa(int x) {
    if(f[x]==x) return x;
    return f[x]=fa(f[x]);
}
int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n;
    n=read();
    for(int i=0;i<n;i++) {
        a[i].x=read();
        a[i].y=read();
        a[i].id=i;
    }
    sort(a,a+n,cmp1);
    int m=0;
    for(int i=1;i<n;i++) {
        e[m].x=a[i].id; e[m].y=a[i-1].id;
        e[m].w=a[i].x-a[i-1].x;
        m++;
    }
    sort(a,a+n,cmp2);
    for(int i=1;i<n;i++) {
        e[m].x=a[i].id; e[m].y=a[i-1].id;
        e[m].w=a[i].y-a[i-1].y;
        m++;
    }
    sort(e,e+m);
    for(int i=0;i<n;i++) f[i]=i;
    ll ans=0;
    for(int i=0;i<m;i++) {
        int fx=fa(e[i].x),fy=fa(e[i].y);
        if(fx!=fy) {
            f[fx]=fy;
            ans+=e[i].w;
        }
    }
    cout<<ans;
    return 0;
}
//校园网真tm卡
