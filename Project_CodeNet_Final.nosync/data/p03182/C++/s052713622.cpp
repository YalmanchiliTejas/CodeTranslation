#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node{
    int l,r;ll v;
}t[800040];
struct inv{
    int l,r;ll val;
}g[200005];
ll n,m,flag[800040];
void build(int x,int l,int r){
    t[x].l=l;t[x].r=r;
    if(l==r) return;
    int mid=(l+r)>>1;
    build((x<<1),l,mid);
    build((x<<1)|1,mid+1,r);
}
void pushdown(int x) {
    if(flag[x]) {
        flag[x<<1]+=flag[x];
        t[x<<1].v+=flag[x];
        flag[(x<<1)|1]+=flag[x];
        t[(x<<1)|1].v+=flag[x];
        flag[x]=0;
    }
}
ll query(int x,int y) {
    int l=t[x].l,r=t[x].r,mid=(l+r)>>1;
    if(r==y) return t[x].v;
    pushdown(x);
    if(y<=mid) return query(x<<1,y);
    else return max(t[x<<1].v,query((x<<1)|1,y));
}
void change(int x,int l,int r,ll val) {
    int lc=t[x].l,rc=t[x].r,mid=(lc+rc)>>1;
    if(l<=lc&&r>=rc) {
        flag[x]+=val;
        t[x].v+=val;
        return;
    }
    pushdown(x);
    if(l<=mid) change(x<<1,l,r,val);
    if(r>mid) change((x<<1)|1,l,r,val);
    t[x].v=max(t[(x<<1)].v,t[(x<<1)|1].v);
}
bool cmp(inv x,inv y){return x.r<y.r;}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d%lld",&g[i].l,&g[i].r,&g[i].val);
    sort(g+1,g+m+1,cmp);
    build(1,1,n);
    int tmp=1;
    for(int i=1;i<=n;i++){
        change(1,i,i,query(1,i));
        while(g[tmp].r==i){
            change(1,g[tmp].l,g[tmp].r,g[tmp].val);
            tmp++;
        }
    }
    printf("%lld",max(t[1].v,0ll));
    return 0;
}