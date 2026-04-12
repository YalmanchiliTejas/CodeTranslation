#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;


template<typename S, S op(S, S)>
struct Doubling {
    vector<vector<S>> v;

    Doubling(const vector<S>& step1, ll p){
        const auto n = step1.size();
        v.resize(p);
        v.at(0) = step1;
        for(ll i = 1; i < p; ++i){
            v.at(i).resize(n);
            for(ll j = 0; j < n; ++j){
                const auto& x = v.at(i - 1).at(j);
                const auto& y = v.at(i - 1).at(x.index);
                v.at(i).at(j) = op(x, y);
            }
        }
    }

    S query(S init, ll nstep){
        S ret = init;
        REP(i, v.size()){
            if((nstep >> i) & 1){
                ret = op(ret, v.at(i).at(ret.index));
            }
        }
        return ret;
    }
};

struct S{ ll sum, index; };
S op(S x, S y){ return S{x.sum + y.sum, y.index }; }

int main(){
    ll n, x, m;
    cin >> n >> x >> m;

    vector<S> step1(m);
    REP(i, m){
        step1.at(i) = {i, (i * i) % m};
    }

    Doubling<S, op> dbl(step1, 40);

    const auto ans = dbl.query(S{0, x}, n);
    cout << ans.sum << endl;

    return 0;
}
