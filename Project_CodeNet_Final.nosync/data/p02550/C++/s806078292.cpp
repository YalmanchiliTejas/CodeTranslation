// #pragma GCC optimize("O3")
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace ::std;
// clang-format off
template<typename T> T nxt() {T res; cin >> res; return res;}
#define tests() for (int _ = nxt<int>(); _ > 0; _--)
#define nxt1(t,n) t (n); cin >> n
#define nxt2(t,n,m) t (n),(m); cin >> n >> m
#define nxt3(t,n,m,k) t (n),(m),(k); cin >> n >> m >> k
#define rep(i, A) for (int i = 0 ; i < A ; i++)
#define ll long long
typedef pair<int,int> pii;typedef pair<ll, ll> pll;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<ll> vl;typedef vector<vl> vvl;
#define dbg(vari) cerr<<#vari<<" = "<<(vari)<<endl;
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){for(T ti : t)s<<ti<<" ";return s; }
#define all(x) (x).begin(), (x).end()
#define last(vec) vec[vec.size()-1]
#define has(c,x) ((c).find(x) != (c).end())
// clang-format on

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    nxt3(ll, N, X, M);

    ll res = X;
    ll last = X;
    map<ll, pair<ll, ll>> midsum;
    rep(i, N - 1) {
        last = (last % M);
        ll tmp = (last * last) % M;
        last = tmp;
        res += tmp;
        if (midsum.find(tmp) == midsum.end()) {
            midsum[tmp] = make_pair(res, i);
        } else {
            ll cycle_length = (i - midsum[tmp].second);
            ll cycle_sum = res - midsum[tmp].first;

            ll remaining_cycles = (N - 2ll - (ll)i) / cycle_length;
            res += remaining_cycles * cycle_sum;
            ll leftover = (N - 2ll - (ll)i) % cycle_length;
            while (leftover > 0) {
                last = (last * last) % M;
                res += last;
                leftover--;
            }
            break;
        }
    }

    cout << res << endl;

    return 0;
}
