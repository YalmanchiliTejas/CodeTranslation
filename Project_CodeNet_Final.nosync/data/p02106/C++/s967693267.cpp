#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define CIN_ONLY if(1)
struct cww{cww(){
    CIN_ONLY{
        ios::sync_with_stdio(false);cin.tie(0);
    }
}}star;
#define fin "\n"
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define DEBUG if(0)
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline void chmin(T &l,T r){l=min(l,r);}
template <typename T>inline void chmax(T &l,T r){l=max(l,r);}
template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}

struct L{
    int v[10];
};
struct node{
    L l;
    L r;
    int flag;
};
L mg(node &v){
    return v.l;
}
L mg(L l,L r){
    L res;
    REP(i,10)res.v[i]=l.v[i]+r.v[i];
    return res;
}
namespace ST{
    node mem[1][4123456];
    int cnt=0;
    node* get(){return mem[cnt++];}
    
}

struct seg_tree{
    int size;
    node *seg;
    void init(int l,int r,int k=0){
        auto &v=seg[k];
        v.flag=0;
        REP(i,10){
            v.l.v[i]=0;
            v.r.v[i]=i;
        }
        if(r-l==1){
            v.l.v[0]=1;
        }
        else if(r-l>1){
            int m=(l+r)/2;
            init(l,m,k*2+1);init(m,r,k*2+2);
            v.l.v[0]=seg[k*2+1].l.v[0]+seg[k*2+2].l.v[0];
        }
    }
    seg_tree(int n){
        size=1;
        while(size<n)size*=2;
        seg=ST::get();
        init(0,size);
    }
    inline void push(int k,int l,int r){
        if(r-l<=1)return;
        auto &v=seg[k];
        auto &lg=seg[2*k+1];
        auto &rg=seg[2*k+2];
        if(v.flag){
            lg.flag=1;
            rg.flag=1;
            v.flag=0;
            {
                L nxt;
                REP(i,10)nxt.v[i]=0;
                REP(i,10)nxt.v[v.r.v[i]]+=lg.l.v[i];
                lg.l=nxt;
                REP(i,10)lg.r.v[i]=v.r.v[lg.r.v[i]];                
            }
            {
                L nxt;
                REP(i,10)nxt.v[i]=0;
                REP(i,10)nxt.v[v.r.v[i]]+=rg.l.v[i];
                rg.l=nxt;
                REP(i,10)rg.r.v[i]=v.r.v[rg.r.v[i]];                
            }
            REP(i,10)v.r.v[i]=i;
        }
    }
#define LQ a,b,k*2+1,l,m
#define RQ a,b,k*2+2,m,r
    L get(int a,int b,int k,int l,int r){
        if(a<=l&&r<=b)return mg(seg[k]);
        push(k,l,r);
        int m=(l+r)/2;
        bool ll=!(m<=a||b<=l);
        bool rr=!(r<=a||b<=m);
        L ret;
        if(ll&&rr)ret=mg(get(LQ),get(RQ));
        else if(ll)ret=get(LQ);
        else ret=get(RQ);
        seg[k].l=mg(mg(seg[k*2+1]),mg(seg[k*2+2]));
        return ret;
    }
    L get(int a,int b){return get(a,b,0,0,size);}
    void update(int a,int b,int k,int l,int r,L v){
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            seg[k].flag=1;
            L nxt;
            REP(i,10)nxt.v[i]=0;
            REP(i,10)nxt.v[v.v[i]]+=seg[k].l.v[i];
            seg[k].l=nxt;
            REP(i,10)seg[k].r.v[i]=v.v[seg[k].r.v[i]];
        }
        else{
            push(k,l,r);
            int m=(l+r)/2;
            update(LQ,v);
            update(RQ,v);
            seg[k].l=mg(mg(seg[k*2+1]),mg(seg[k*2+2]));
        }
    }
    void update(int a,int b,int x,int y){
        L v;
        REP(i,10)v.v[i]=i;
        v.v[x]=y;
        update(a,b,0,0,size,v);
    }
};
typedef vector<int> V;
typedef vector<V> Graph;
typedef pair<int,int> P;
void euler_tour(int v,int p,Graph &C,vector<P>& seg,int &cnt){
    int l=cnt++;
    for(auto &e:C[v])
        if(e!=p)
            euler_tour(e,v,C,seg,cnt);
    int r=cnt++;
    seg[v]=P(l,r);
}



int main(){
    int n,q;
    cin>>n>>q;
    Graph g(n);
    REP(i,n-1){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<P> s(2*n);
    {
        int cnt=0;
        euler_tour(0,0,g,s,cnt);
    }
    int m=n*2;
    seg_tree st(m);
    REP(qq,q){
        int t,r,x,y;
        cin>>t>>r>>x>>y;
        int bg=s[r].fi;
        int ed=s[r].se+1;
        if(t==1){
            int res=0;
            auto l=st.get(bg,ed);
            FOR(i,x,y+1)res+=l.v[i];
            //   REP(i,10) cout<<l.v[i]/2<<" ";cout<<endl;
            cout<<res/2<<endl;
        }
        else{
            st.update(bg,ed,x,y);
        }


    }
    return 0;
}