#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;
using namespace atcoder;

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return (int)(-1);
}
int target;
bool f(int v){
    return v < target;
}

int main(){
    ll N,Q;
    cin >> N >> Q;
    vector<int> A(N);
    segtree<int, op, e> seg(N);
    rep(i,N){
        cin >> A[i];
        seg.set(i,A[i]);
    }
    vector<int> a(Q),b(Q),c(Q);
    rep(i,Q){
        cin >> a[i] >> b[i] >> c[i];
    }
    int t,x,v;
    rep(i,Q){
        t = a[i];
        x = b[i];
        v = c[i];
        if(t==1){
            x--;
            seg.set(x,v);
        }else if(t==2){
            x--;
            cout << seg.prod(x,v) << endl;
        }else{
            target = v;
            x--;
            cout << seg.max_right<f>(x) + 1 << endl;
        }
    }
}