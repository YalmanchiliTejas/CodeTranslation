#include<bits/stdc++.h>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define RFOR(i,a,b) for(int i=(b-1); i>=(a); i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define pb push_back
using ll = long long;
using D = double;
using LD = long double;
using P = pair<int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int op(int a, int b) {return max(a,b);}

int e() {return -1;}

int target;
bool f(int v) {return v < target;}

int main(){
    int n,q; cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    segtree<int, op, e> seg(a);

    rep(_, q){
        int t; cin >> t;
        if(t == 1){
            int x,v; cin >> x >> v; x--;
            seg.set(x, v);
        }
        else if(t == 2){
            int l,r; cin >> l >> r; l--;
            cout << seg.prod(l,r) << endl;
        }
        else if(t == 3){
            int p; cin >> p >> target; p--;
            cout << seg.max_right<f>(p)+1 << endl;
        }
    }
}
