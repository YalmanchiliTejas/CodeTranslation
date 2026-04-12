#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;

ll binary_search(
    ll lo, ll hi, function<bool(ll)> is_ok,
    bool maximize
){
    while(lo < hi){
        if(maximize){
            const ll mid = (lo + hi + 1) / 2;
            if(is_ok(mid)){
                lo = mid;
            }else{
                hi = mid - 1;
            }
        }else{
            ll mid = (lo + hi - 1) / 2;
            if(is_ok(mid)){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
    }
    return lo;
}

using S = ll;
S e(){ return numeric_limits<ll>::min(); }
S op(S a, S b){ return max(a, b); }

int main(){
    ll n, q;
    cin >> n >> q;
    vector<S> a(n);
    REP(i, n){ cin >> a.at(i); }
    segtree<S, op, e> st(a);
    REP(i, q){
        ll t;
        cin >> t;
        if(t == 1){
            ll xi, vi;
            cin >> xi >> vi;
            xi--;
            st.set(xi, vi);
        }else if(t == 2){
            ll l, r;
            cin >> l >> r;
            l--; r--;
            cout << st.prod(l, r + 1) << endl;
        }else{
            ll xi, vi;
            cin >> xi >> vi;
            xi--;
            if(st.prod(xi, n) < vi){
                cout << n + 1 << endl;
            }else{
                cout << ::binary_search(
                    xi, n - 1,
                    [&](ll x){ return st.prod(xi, x + 1) >= vi; },
                    false
                ) + 1 << endl;
            }
        }
    }
    return 0;
}
