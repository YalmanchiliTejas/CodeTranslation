#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

class LazySegmentTree{
private:
    vector<ll> node, lazy;
    ll SIZE;
    vector<bool> lazyflag;
public:
    LazySegmentTree(int n){
        SIZE = 1;
        while(SIZE<n) SIZE*=2;
        node = lazy = vector<ll>(2*SIZE+1,0);
        lazyflag = vector<bool> (2*SIZE+1,false);
    }
    void eval(int k, int l, int r){
        if(lazyflag[k]){
            node[k] += lazy[k];
            if(r-l>1){
                lazy[k*2+1] += lazy[k];
                lazy[k*2+2] += lazy[k];
                lazyflag[k*2+1] = lazyflag[k*2+2] = true;
            }
            lazyflag[k] = false;
            lazy[k] = 0;
        }
    }     
    void add(int a, int b, ll x, int k=0, int l=0, int r=-1){
        if(r<0) r=SIZE;
        eval(k,l,r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += x;
            lazyflag[k]=true;
            eval(k, l, r);
        }
        else{
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = max(node[2*k+1], node[2*k+2]);
        }
    }    
    ll getmax(int a, int b, int k=0, int l=0, int r=-1){
        if(r<0) r=SIZE;
        eval(k,l,r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};

int N,M;
int main(){
    cin >> N >> M;
    vector<vector<pair<int,ll>>> v(N+1);
    int l,r;
    ll a;
    for(int i=0;i<M;i++){
        cin >> l >> r >> a;
        v[r].push_back({l,a});
    }
    LazySegmentTree segtree(N+1);
    for(int i=1;i<=N;i++){
        ll sum = 0;
        for(auto x:v[i]) sum += x.second;
        segtree.add(i,i+1,sum+segtree.getmax(1,i));
        for(auto x:v[i]) segtree.add(x.first,i,x.second);
    }
    cout << segtree.getmax(1,N+1) << endl;
}