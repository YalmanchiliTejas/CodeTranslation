#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define Clear(a) a = decltype(a)()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define vec vector
typedef long long ll;
typedef pair<ll,ll> P;
//const ll big=998244353;
const ll big=1000000007LL;
const ll INF=1e18;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
ll max(ll x,ll y){
    if(x>y)return x;
    else return y;
}
ll min(ll x,ll y){
    if(x<y)return x;
    else return y;
}
ll expm(ll x,ll y){
    if(y==0)return 1;//0^0=1
    if(x==1||x==0)return x;
    if(y%2==1)return (expm(x,y-1)*x)%big;
    ll t=expm(x,y/2);
    return (t*t)%big;
}
ll exp(ll x,ll y){
    if(y==0)return 1;//0^0=1
    if(x==1||y==0)return x;
    if(y%2==1)return exp(x,y-1)*x;
    ll t=exp(x,y/2);
    return t*t;
}


struct segtree{//maxをとるseg木
    int n;
    int size;
    vector<ll> seg;
    segtree(const int n_): n(1<<20) , size(n_) , seg(1<<21 , 0){};
    ll get(int l,int r){//[l,r)
        return get_sub(l,r,0,0,n);
    }
    ll get_sub(int l,int r,int k,int a,int b){//[l,r)での答えがほしい いま[a,b)を見ている kは[a,b)を持っているところ(vector segのindex)
        if(l>=b || r<=a)return 0;//完全に外にいるときは小さいのを返しておけばよい
        if(l<=a && b<=r)return seg[k];//完全に中にいるときはそのまま返せばよい
        //子供をたどる
        return max(get_sub(l,r,2*k+1,a,(a+b)/2) , get_sub(l,r,2*k+2,(a+b)/2,b));
    }
    void change(int i,ll x){//0_indexedでi番めをxに変える
        i+=n-1;
        seg[i]=x;
        while(i>0){
            i=(i-1)/2;
            ll t=seg[i];
            seg[i]=max(seg[2*i+1],seg[2*i+2]);
            if(t==seg[i])break;
        }
        return;
    }
    void add(int i,ll x){//i番めにxを加算
        i+=n-1;
        seg[i]+=x;
        while(i>0){
            i=(i-1)/2;
            ll t=seg[i];
            seg[i]=max(seg[2*i+1],seg[2*i+2]);
            if(t==seg[i])break;
        }
        return;
    }
    int lower_bound(int i,int v){//v以上の値を持つindexをreturnする
        return lower_bound_sub(i,size,0,0,n,v);
    }
    int lower_bound_sub(int l,int r,int k,int a,int b,ll v){//[l,r)においてv以上の値を持つ最小のindexを返すのが目標 今[a,b)を持つようなseg[k]を見ている
        if(r<=a||l>=b)return size;
        if(seg[k]<v)return size;
        if(k>=n-1)return k-n+1;
        int res;
        res=lower_bound_sub(l,r,2*k+1 , a,(a+b)/2,v);
        if(res!=size)return res;
        else return lower_bound_sub(l,r,2*k+2,(a+b)/2,b,v);
    }
};


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(10);
    /*--------------------------------*/

    int n,q;cin >> n >> q;
    segtree seg(n);
    vector<ll> out;
    rep(i,n){
        ll a;cin >> a;
        seg.change(i,a);
    }
    rep(i,q){
        int t;cin >> t;
        if(t==1){
            int x;ll v;cin >> x >> v;x--;
            seg.change(x,v);
        }
        else if(t==2){
            int l,r;cin >> l >> r;l--;r--;
            out.emplace_back(seg.get(l,r+1));
        }
        else{
            int x;ll v;cin >> x >> v;x--;
            out.emplace_back(seg.lower_bound(x,v)+1);
        }
    }
    rep(i,out.size())cout << out[i] << '\n';
}