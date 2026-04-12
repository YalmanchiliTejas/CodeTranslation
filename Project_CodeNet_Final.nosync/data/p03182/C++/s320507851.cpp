#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T, typename U>
struct lazy_segment_tree{
    int n;
    int H;
    T base;
    vector<T> segtree;
    vector<U> lazytree;
    vector<bool> isempty;
    function<T(const T&, const T&)> join;
    function<T(int, const U&, const T&)> assign;
    function<U(const U&,const U&)> lazyassign;

    lazy_segment_tree(vector<T> seq, 
    function<T(const T&, const T&)> join, 
    function<T(int, const U&, const T&)> assign,
    function<U(const U&,const U&)> lazyassign,
    T base) : join(join), assign(assign), lazyassign(lazyassign), base(base){
        n = seq.size();
        H = 32 - __builtin_clz(n);
        segtree.resize(2*n);
        lazytree.resize(n);
        isempty.resize(n,1);
        for(int i=0;i<n;i++){
            segtree[n+i]=seq[i];
        }
        for(int i=n-1;i>=1;i--){
            segtree[i]=join(segtree[(i<<1)], segtree[(i<<1)|1]);
        }
    }
    void calc(int pos, int h){
        segtree[pos]=join(segtree[(pos<<1)],segtree[(pos<<1)|1]);
        if(!isempty[pos]){
            segtree[pos]=assign(h,lazytree[pos],segtree[pos]);
        }
    }
    void apply(int pos, U value, int h){
        segtree[pos]=assign(h, value, segtree[pos]);
        if(pos<n){
            if(!isempty[pos]){
                lazytree[pos]=lazyassign(value, lazytree[pos]);
            }
            else{
                lazytree[pos] = value;
            }
            isempty[pos]=0;
        }
    }
    void updatenode(int pos){
        int h=0;
        pos+=n;
        while(pos>1){
            h++;
            pos>>=1;
            calc(pos, h);
        }
    }
    void push(int pos){
        int h=H;
        for(pos+=n;h;--h){
            int x=(pos>>h);
            if(!isempty[x]){
                apply((x<<1), lazytree[x], h-1);
                apply((x<<1)|1, lazytree[x], h-1);
                isempty[x]=1;
            }
        }
    }
    void updaterange(int l, int r, U value){
        push(l);
        push(r);
        int k=0;
        int l0=l, r0=r;
        for(l+=n, r+=n+1;l<r;l>>=1, r>>=1, k++){
            if(l&1){
                apply(l++, value, k);
            }
            if(r&1){
                apply(--r, value,k);
            }
        }
        updatenode(l0);
        updatenode(r0);
    }
    T query(int l, int r){
        push(l);
        push(r);
        T ansl=base;
        T ansr=base;
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
            if(l&1){
                ansl=join(ansl, segtree[l++]);
            }        
            if(r&1){
                ansr=join(segtree[--r], ansr);
            }
        }
        return join(ansl,ansr);
    }
};
struct Range{
    int l,r,val;
    Range(){}
    Range(int l,int r,int val) : l(l), r(r), val(val) {}
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<Range> rangesbyl(m);
    for(auto &[l,r,val] : rangesbyl){
        cin>>l>>r>>val;
    }
    vector<Range> rangesbyr = rangesbyl;
    sort(rangesbyl.begin(), rangesbyl.end(), [&](const Range &x, const Range &y){return x.l < y.l;});
    sort(rangesbyr.begin(), rangesbyr.end(), [&](const Range &x, const Range &y){return x.r < y.r;});
    lazy_segment_tree<ll,ll> segtree(vector<ll>(n+1),
    [&](const ll &x, const ll &y){
        return x>y ? x : y;
    },
    [&](int h, const ll& x, const ll& lazy){
        return x+lazy;
    },
    [&](const ll& x, const ll& y){
        return x+y;
    }
    ,-1e18);
    ll ans = 0;
    for(int i=1,j=0,k=0;i<=n;i++){
        while(k<m && rangesbyl[k].l<=i){
            segtree.updaterange(0,rangesbyl[k].l-1, rangesbyl[k].val);
            ++k;
        }
        while(j<m && rangesbyr[j].r<i){
            segtree.updaterange(0,rangesbyr[j].l-1, -rangesbyr[j].val);
            ++j;
        }
        ll curr = segtree.query(0,i-1);
        ans = max(ans, curr);
        segtree.updaterange(i,i,curr);
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}