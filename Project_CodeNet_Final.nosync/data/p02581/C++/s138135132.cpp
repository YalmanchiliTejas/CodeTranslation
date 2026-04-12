#line 2 "header.hpp"

//%snippet.set('header')%
//%snippet.fold()%
#ifndef HEADER_H
#define HEADER_H

// template version 2.0
using namespace std;
#include <bits/stdc++.h>

// varibable settings
const long long INF = 1e18;
template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define _rrep(i, n) rrepi(i, 0, n)
#define rrepi(i, a, b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)
#define r_rep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)
#define each(i, a) for (auto &&i : a)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(...) make_tuple(__VA_ARGS__)
#define ub upper_bound
#define lb lower_bound
#define lpos(A, x) (lower_bound(all(A), x) - A.begin())
#define upos(A, x) (upper_bound(all(A), x) - A.begin())
template <class T> inline void chmax(T &a, const T &b) { if ((a) < (b)) (a) = (b); }
template <class T> inline void chmin(T &a, const T &b) { if ((a) > (b)) (a) = (b); }
template <typename X, typename T> auto make_table(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y, z, zs...); return vector<decltype(cont)>(x, cont); }

#define cdiv(a, b) (((a) + (b)-1) / (b))
#define is_in(x, a, b) ((a) <= (x) && (x) < (b))
#define uni(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define slice(l, r) substr(l, r - l)

typedef long long ll;
typedef long double ld;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;

template <typename T>
using PQ = priority_queue<T, vector<T>, greater<T>>;
void check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp; assert(cin.eof() == 1); }

#if defined(PCM) || defined(LOCAL)
#else
#define dump(...) ;
#define dump_1d(...) ;
#define dump_2d(...) ;
#define cerrendl ;
#endif

#endif /* HEADER_H */
//%snippet.end()%
#line 2 "solve2.cpp"
template<class T=ll> using vec = vector<T>;
struct Fast { Fast() { std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int solve() {
    ll n;cin>>n;
    vector<ll> a(3*n);
    rep(i, 3*n) {
        cin>>a[i];
        a[i]--;
    }
    dump(a);
    a.pb(n);
    a.pb(n+1);

    vec<vec<ll>> dp = make_table(n+2, n+2, -INF);
    dp[a[0]][a[1]] = 0;
    dp[a[1]][a[0]] = 0;
    ll now = 2;

    vec<ll> buf(3);
    ll add = 0;
    vec<tuple<ll, ll, ll>> updates;
    vec<ll> local(n+2, -INF);
    local[a[0]] = 0;
    local[a[1]] = 0;
    while(true){
        cerrendl;
        dump(now);
        buf[0] = a[now];
        buf[1] = a[now+1];
        buf[2] = a[now+2];
        sort(all(buf));
        updates.clear();

        ll mv = *max_element(all(local));

        if (buf[0] == buf[2]){
            add++;
        }
        else{
            if (buf[0] == buf[1]){
                ll p = buf[0];
                ll q = buf[2];
                rep(x, n) updates.pb(mt(q, x, dp[p][x]+1));
            }
            else if (buf[1] == buf[2]){
                ll p = buf[1];
                ll q = buf[0];
                rep(x, n) updates.pb(mt(q, x, dp[p][x]+1));
            }
            ll p = buf[0];
            ll q = buf[1];
            ll r = buf[2];
            updates.pb(mt(q, r, dp[p][p]+1));
            updates.pb(mt(p, r, dp[q][q]+1));
            updates.pb(mt(p, q, dp[r][r]+1));

            // (2, 1)
            updates.pb(mt(p, q, mv));
            updates.pb(mt(p, r, mv));
            updates.pb(mt(r, q, mv));

            // (1, 2)
            rep(x, n){
                updates.pb(mt(x, p, local[x]));
                updates.pb(mt(x, q, local[x]));
                updates.pb(mt(x, r, local[x]));
            }
        }

        dump(updates);
        for (auto [x, y, v] : updates){
            chmax(dp[x][y], v);
            chmax(dp[y][x], v);
            chmax(local[x], v);
            chmax(local[y], v);
        }

        if (now == 3*n - 1) break;
        now += 3;
    }

    ll ans = 0;
    rep(i, n+2)rep(j, n+2) chmax(ans, dp[i][j]);
    cout << ans + add << endl;
    return 0; 
}


int main(){/*{{{*/
    solve();
    check_input();
    return 0;
}/*}}}*/
