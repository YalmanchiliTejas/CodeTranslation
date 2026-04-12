#include<bits/stdc++.h>
#define P printf
#define S scanf
#define PII pair<int,int>
#define x first
#define y second
#define eb emplace_back
#define pb push_back
#define heap priority_queue
#define Q queue
#define V vector
#define T top
#define F front
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define PLL pair<ll,ll>
using namespace std;
const long long N=200005;
ll seg[4*N];
struct A{
    int p,ch,l,r;
    ll w;
    bool operator <(const A& o) const{
        return p<o.p;
    }
};
int idx=0;
A swp[2*N];
ll lazy[4*N];
void update(int l,int r,int now,int LL,int RR,ll val){
    if(lazy[now]){
        seg[now]+=lazy[now];
        if(l!=r){
            lazy[now<<1]+=lazy[now];
            lazy[(now<<1)+1]+=lazy[now];
        }
        lazy[now]=0;
    }
    if(l>RR || r<LL) return ;
    if(l>=LL && r<=RR){
        seg[now]+=val;
        if(l!=r){
            lazy[now<<1]+=val;
            lazy[(now<<1)+1]+=val;
        }
        return ;
    }
    int mid=(l+r)>>1,L=now<<1,R=L+1;
    update(l,mid,L,LL,RR,val); update(mid+1,r,R,LL,RR,val);
    seg[now]=max(seg[L],seg[R]);
}
ll query(int l,int r,int now,int LL,int RR){
    if(lazy[now]){
        seg[now]+=lazy[now];
        if(l!=r){
            lazy[now<<1]+=lazy[now];
            lazy[(now<<1)+1]+=lazy[now];
        }
        lazy[now]=0;
    }
    if(l>RR || r<LL) return -1e18;
    if(l>=LL && r<=RR) return seg[now];
    int mid=(l+r)>>1,L=now<<1,R=L+1;
    return max(query(l,mid,L,LL,RR),query(mid+1,r,R,LL,RR));
}
int main(){
    int n,m;
    S(" %d %d",&n,&m);
    FOR(i,0,m-1){
        int l,r;
        ll w;
        S(" %d %d %lld",&l,&r,&w);
        swp[2*i]={l,0,l,r,w};
        swp[2*i+1]={r+1,1,l,r,w};
    }
    lazy[1]=-1e14;
    sort(swp,swp+2*m);
    ll val=0,best=0;
    FOR(i,1,n){
        while(idx<2*m && swp[idx].p==i){
//            P("##%d %d %lld ",swp[idx].l,swp[idx].r,swp[idx].w);
            if(swp[idx].ch){
//                P("OUT\n");
                update(1,n,1,swp[idx].l,swp[idx].r,swp[idx].w);
                val-=swp[idx].w;
            }else{
//                P("IN\n");
                val+=swp[idx].w;
            }
            idx++;
        }
        ll dp=-1e14;
        if(i>1) dp=max(dp,max(val,val+query(1,n,1,1,i-1)));
        else dp=max(dp,val);
        best=max(dp,best);
//        P("==%lld %lld %lld\n",val,dp,query(1,n,1,1,i-1));
        update(1,n,1,i,i,1e14+dp-val);
    }
    P("%lld",best);
    return 0;
}
