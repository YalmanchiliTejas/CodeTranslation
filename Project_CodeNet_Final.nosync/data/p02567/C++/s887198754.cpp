#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i = 0; i < (int)(n); i ++)
#define irep(i,n) for (int i = (int)(n) - 1;i >= 0;--i)
using namespace std;
using namespace atcoder;
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr int INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;// = 998244353;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;

using S = int;
S op(S a,S b) {return max(a,b);}
S e() {return -1;}
S target;
bool f(S a) {return a < target;}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N,Q; cin >> N >> Q;
    vector<S> A(N);
    rep(i,N) cin >> A[i];

    segtree<S,op,e> st(A);
    rep(i,Q) {
        int t; cin >> t;
        if (t == 1) {
            int x; S v;cin >> x >> v;
            --x;
            st.set(x,v);
        } else if (t == 2) {
            int l,r; cin >> l >> r;
            --l;
            cout << st.prod(l,r) << '\n';
        } else {
            int x; cin >> x >> target;
            --x;
            cout << st.max_right<f>(x) + 1 << '\n';
        }
    }
    return 0;
}