#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=(ll)1e18;

struct LazySegmentTree{
private:
    int n;
    vector<ll> node,assign,add;
public:
    LazySegmentTree(int sz){
        n=1;
        while(n<sz)n*=2;
        node.resize(2*n-1);
        assign.resize(2*n-1,LINF);
        add.resize(2*n-1);
    }
    void eval(int k,int l,int r){
        if(assign[k]!=LINF){
            node[k]=assign[k];
            if(r-l>1){
                assign[2*k+1]=assign[2*k+2]=assign[k];
                add[2*k+1]=add[2*k+2]=0;
            }
            assign[k]=LINF;
        }
        if(add[k]!=0){
            node[k]+=add[k];
            if(r-l>1){
                if(assign[2*k+1]!=LINF){
                    assign[2*k+1]+=add[k];
                }
                else{
                    add[2*k+1]+=add[k];
                }
                if(assign[2*k+2]!=LINF){
                    assign[2*k+2]+=add[k];
                }
                else{
                    add[2*k+2]+=add[k];
                }
            }
            add[k]=0;
        }
    }
    void update(int a,int b,int q,ll x,int k=0,int l=0,int r=-1){
        if(r==-1)r=n;
        eval(k,l,r);
        if(b<=l||r<=a)return;
        if(a<=l&&r<=b){
            if(q==0){
                assign[k]=x;
            }
            else{
                add[k]=x;
            }
            eval(k,l,r);
        }
        else{
            update(a,b,q,x,2*k+1,l,(l+r)/2);
            update(a,b,q,x,2*k+2,(l+r)/2,r);
            node[k]=max(node[2*k+1],node[2*k+2]);
        }
    }
    ll get(int a,int b,int k=0,int l=0,int r=-1){
        if(r==-1)r=n;
        eval(k,l,r);
        if(b<=l||r<=a)return 0LL;
        if(a<=l&&r<=b){
            return node[k];
        }
        else{
            return max(get(a,b,2*k+1,l,(l+r)/2),get(a,b,2*k+2,(l+r)/2,r));
        }
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    pair<int,pair<int,ll>> p[m];
    for(int i=0;i<m;i++){
        int l,r;
        ll a;
        cin>>l>>r>>a;
        p[i]={r,{l-1,a}};
    }
    sort(p,p+m);
    LazySegmentTree dp(n);
    for(int i=0;i<m;i++){
        int l=p[i].second.first;
        int r=p[i].first;
        ll a=p[i].second.second;
        dp.update(l,r,1,a);
        ll mx=max(dp.get(0,r),0LL);
        if(r!=n)dp.update(r,n,0,mx);
    }
    cout<<max(dp.get(0,n),0LL)<<endl;
}