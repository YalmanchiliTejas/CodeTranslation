#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
const ll INF=1LL<<30;
const ll LINF=1LL<<60;
const double eps=1e-5;
const ll MOD=1e+7;
template<typename T>void chmin(T &a,T b){a=min(a,b);};
template<typename T>void chmax(T &a,T b){a=max(a,b);};
struct Segtree{
    int n,hi;
    vector<ll> node,lazy;
    Segtree(int n_){
        n=1;hi=1;
        while(n<n_)n<<=1,++hi;
        node.assign(2*n,-LINF);
        lazy.assign(2*n,0);
    }
    ll eval(int k){
        node[k]=(node[k]==-LINF?lazy[k]:node[k]+lazy[k]);
        if(lazy[k]==0)return node[k];
        if(k<n){
            lazy[k<<1]+=lazy[k];
            lazy[k<<1|1]+=lazy[k];
        }
        lazy[k]=0;
        return node[k];
    }
    void update(int a,int b,ll x){
        int l=a+n,r=b+n;
        for(int i=hi;i>0;i--)eval(l>>i),eval(r>>i);
        for(++r;l<r;l>>=1,r>>=1){
            if(l&1)lazy[l++]+=x;
            if(r&1)lazy[--r]+=x;
        }
        l=a+n,r=b+n;
        while(l>>=1)node[l]=max(eval(l<<1),eval(l<<1|1));
        while(r>>=1)node[r]=max(eval(r<<1),eval(r<<1|1));
    }
    ll query(int a,int b){
        int l=a+n,r=b+n;
        for(int i=hi;i>0;i--)eval(l>>i),eval(r>>i);
        ll vl=-LINF,vr=-LINF;
        for(++r;l<r;l>>=1,r>>=1){
            if(l&1)vl=max(vl,eval(l++));
            if(r&1)vr=max(eval(--r),vr);
        }
        return max(vl,vr);
    }
};
int main(){
    int n,m;cin>>n>>m;
    vector<vector<ll>> l(n+10);
    vector<vector<P>> r(n+10);
    for(int i=0;i<m;i++){
        int l1,r1,a;cin>>l1>>r1>>a;
        l[l1].push_back(a);
        r[r1].push_back(P(a,l1));
    }
    ll ans=0;
    Segtree tree(n+10);
    for(int i=1;i<=n;i++){
        for(auto a:l[i]){
            tree.update(0,i-1,a);
        }
        ll dp=tree.query(0,i-1);
        ans=max(ans,dp);
        tree.update(i,i,dp);
        for(auto a:r[i]){
            tree.update(0,a.second-1,-a.first);
        }
    }
    cout<<ans<<endl;
}   
