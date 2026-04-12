#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

template<typename T> class segtree {
private:
    int n,sz,h;
    vector<T> node, lazy;
    void eval(int k) {
        if(lazy[k]){
            node[k] += lazy[k];
            if(k < n) {
                lazy[k*2] += lazy[k], lazy[k*2+1] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

public:
    segtree(vector<T>& v) : sz((int)v.size()), h(0) {
        n = 1;
        while(n < sz) n *= 2, h++;
        node.resize(2*n, numeric_limits<T>::min());
        lazy.resize(2*n, 0);
        for(int i = 0; i < sz; i++) node[i+n] = v[i];
        for(int i = n-1; i >= 1; i--) node[i] = max(node[2*i], node[2*i+1]);
    }
    void range(int a, int b, T x) {
        a += n, b += n - 1;
        for(int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        int ta = a, tb = b++;
        while(a < b){
            if(a & 1) lazy[a++] += x;
            if(b & 1) lazy[--b] += x;
            a >>= 1, b >>= 1;
        }
        while(ta >>= 1, tb >>= 1, ta){
            if(!lazy[ta]){
                eval(2*ta), eval(2*ta+1), node[ta] = max(node[2*ta], node[2*ta+1]);
            }
            if(!lazy[tb]){
                eval(2*tb), eval(2*tb+1), node[tb] = max(node[2*tb], node[2*tb+1]);
            }
        }
    }
    T query(int a, int b) {
        a += n, b += n - 1;
        for(int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        b++;
        T res1 = numeric_limits<T>::min(), res2 = numeric_limits<T>::min();
        while(a < b) {
            if(a & 1) eval(a), res1 = max(res1, node[a++]);
            if(b & 1) eval(--b), res2 = max(res2, node[b]);
            a >>= 1, b >>= 1;
        }
        return max(res1, res2);
    }
    void print(){for(int i = 0; i < sz; i++) cout<<query(i,i+1)<< " ";cout<<endl;}
};


int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> v(n+2);
    segtree<ll> sg(v);
    vector<vector<pair<pair<ll,ll>,ll> > >  p(n+2);
    rep(i,m){
        ll l,r,a;
        cin >> l >> r >> a;
        p[r].push_back(MP(MP(l,r),a));
    }
    for(int i=1;i<=n;i++){
        ll k = sg.query(0,i);
        sg.range(i,i+1,k);
        for(auto x:p[i]){
            ll l = x.first.first;
            ll r = x.first.second;
            ll a = x.second;
            sg.range(l,r+1,a);
        }
        //sg.print();
    }
    
    cout << sg.query(0,n+1) << endl;
    return 0;
}