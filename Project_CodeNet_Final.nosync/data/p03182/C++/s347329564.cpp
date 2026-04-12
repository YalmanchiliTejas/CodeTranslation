#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vp;
typedef pair<pii,int> ppi;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a/gcd(a,b)*b;
}

class LazySegmentTree{
private:
    int n;
    vector<long long> node, lazy;
    long long node_init = 0; // sum, update
    //long long node_init = -LINF; // max
    //long long node_init = LINF; // min
    long long lazy_init = 0; // default
    //long long lazy_init = LINF; // min, update (存在しない値)

    long long lazy_update(long long a,long long b){
        return a + b; // sum query
        //return max(a,b); // max query
        //return min(a,b); // min query
        //return b; // update query
    }

    long long node_update(long long a, long long b, int l, int r){ // lazy を node に反映
        return a + b; // min, max query
        //return b; // update query
        //return b * (r-l); // sum query
    }

    long long combine(long long a,long long b){
        //return a+b; // sum query
        return max(a,b); // max query
        //return min(a,b); // min query
    }

public:
    LazySegmentTree(){}
    LazySegmentTree(vector<long long> in){
        n = 1;
        while(n < in.size())n <<= 1;
        node = vector<long long>(2*n, node_init);
        lazy = vector<long long>(2*n, lazy_init);
        for(int i = n-1+in.size()-1; i >= 0; i--){
            if(n-1 <= i)node[i] = in[i-(n-1)];
            else node[i] = combine(node[i*2+1], node[i*2+2]);
        }
    }
    void eval(int k, int l, int r){
        if(lazy[k] != lazy_init){
            node[k] = node_update(node[k], lazy[k], l, r);
            if(r - l > 1){
                lazy[2*k+1] = lazy_update(lazy[2*k+1], lazy[k]);
                lazy[2*k+2] = lazy_update(lazy[2*k+2], lazy[k]);
            }
            lazy[k] = lazy_init;
        }
    }
    void update(int a, int b, long long x, int k = 0, int l = 0, int r = -1){
        if(r < 0)r = n;
        eval(k,l,r);
        if(b <= l || r <= a)return;
        if(a <= l && r <= b){
            lazy[k] = x;
            eval(k,l,r);
        }else{
            update(a,b,x,2*k+1,l,(l+r)/2);
            update(a,b,x,2*k+2,(l+r)/2,r);
            node[k] = combine(node[2*k+1], node[2*k+2]);
        }
    }
    long long query(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0)r = n;
        if(b <= l || r <= a)return node_init;
        eval(k,l,r);
        if(a <= l && r <= b)return node[k];
        return combine(query(a,b,2*k+1,l,(l+r)/2), query(a,b,2*k+2,(l+r)/2,r));
    }
    void show(){
        cout << "node :";
        for(int i = 0; i < 2*n-1; i++){
            if(i == n-1)cout << "     ";
            cout << " " << node[i];
        }
        cout << endl;
        cout << "lazy :";
        for(int i = 0; i < 2*n-1; i++){
            if(i == n-1)cout << "     ";
            cout << " " << lazy[i];
        }
        cout << endl;
    }
};

signed main(void) {
    int n,m;
    cin >> n >> m;
    vector<vp> v(n+1);
    rep(i,m){
        int l,r,a;
        cin >> l >> r >> a;
        v[r].push_back(pii(l,a));
    }
    LazySegmentTree dp = LazySegmentTree(vi(n+1));
    int ind = 0;
    loop(i,1,n+1){
        //cout << i << " " << dp.query(0,i) << endl;
        dp.update(i,i+1,dp.query(0,i));
        rep(j,v[i].size()){
            dp.update(v[i][j].first, i+1, v[i][j].second);
        }
        //dp.show();
    }
    cout << dp.query(0,n+1) << endl;
}
