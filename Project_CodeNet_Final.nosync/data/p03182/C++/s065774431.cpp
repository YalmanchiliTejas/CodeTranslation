#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cctype>
#define qmin(x,y) (x=min(x,y))
#define qmax(x,y) (x=max(x,y))
using namespace std;

inline char gc() {
//  static char buf[100000],*p1,*p2;
//  return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
    return getchar();
}

template<class T>
int read(T &ans) {
    ans=0;char ch=gc();T f=1;
    while(!isdigit(ch)) {
        if(ch==EOF) return -1;
        if(ch=='-') f=-1;
        ch=gc();
    }
    while(isdigit(ch))
        ans=ans*10+ch-'0',ch=gc();
    ans*=f;return 1;
}

template<class T1,class T2>
int read(T1 &a,T2 &b) {
    return read(a)!=EOF&&read(b)!=EOF?2:EOF;
}

template<class T1,class T2,class T3>
int read(T1 &a,T2 &b,T3 &c) {
    return read(a,b)!=EOF&&read(c)!=EOF?3:EOF;
}

typedef long long ll;
const int Maxn=3100000;
const int inf=0x3f3f3f3f;
const ll mod=1000000007;

int tl[Maxn],tr[Maxn],n,m;
ll tn[Maxn],flag[Maxn];

void build(int root,int l,int r) {
    tl[root]=l;tr[root]=r;
    int mid=l+r>>1;
    if(l==r) return;
    build(root<<1,l,mid);
    build((root<<1)|1,mid+1,r);
}

inline void update(int root) {
    tn[root]=max(tn[root<<1],tn[(root<<1)|1]);
}

void pushdown(int root) {
    if(flag[root]) {
        flag[root<<1]+=flag[root];
        tn[root<<1]+=flag[root];
        flag[(root<<1)|1]+=flag[root];
        tn[(root<<1)|1]+=flag[root];
        flag[root]=0;
    }
}

ll query(int root,int x) {
    int l=tl[root],r=tr[root],mid=l+r>>1;
    if(r==x) return tn[root];
    pushdown(root);
    if(x<=mid) return query(root<<1,x);
    else return max(tn[root<<1],query((root<<1)|1,x));
}

void change(int root,int l,int r,ll x) {
    int lc=tl[root],rc=tr[root],mid=lc+rc>>1;
    if(l<=lc&&r>=rc) {
        flag[root]+=x;
        tn[root]+=x;
        return;
    }
    pushdown(root);
    if(l<=mid) change(root<<1,l,r,x);
    if(r>mid) change((root<<1)|1,l,r,x);
    update(root);
}

struct node {
    int l,r;
    ll x;
}b[Maxn];

int cmp(node a,node b) {
    return a.r<b.r;
}

signed main() {
//  freopen("test.in","r",stdin);
    read(n,m);
    for(int i=1;i<=m;i++)
        read(b[i].l,b[i].r,b[i].x);
    sort(b+1,b+m+1,cmp);
    build(1,1,n);
    int zhy=1,nh=1;
    for(int i=1;i<=n;i++) {
        change(1,i,i,query(1,i));
        while(b[nh].r==i) {
            change(1,b[nh].l,b[nh].r,b[nh].x);
            nh++;
        }
    }
    printf("%lld",max(tn[1],0ll));
    return 0;
}