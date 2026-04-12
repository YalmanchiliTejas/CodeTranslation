#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")

#include <bits/stdc++.h>

// 汎用マクロ
#define ALL_OF(x) (x).begin(), (x).end()
#define REP(i,n) for (long long i=0, i##_len=(n); i<i##_len; i++)
#define RANGE(i,is,ie) for (long long i=(is), i##_end=(ie); i<=i##_end; i++)
#define DSRNG(i,is,ie) for (long long i=(is), i##_end=(ie); i>=i##_end; i--)
#define UNIQUE(v) { sort((v).begin(), (v).end()); (v).erase(unique((v).begin(), (v).end()), (v).end()); }
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return true;} return false; }
template<class T> bool chmin(T &a, const T &b) {if (a > b) {a = b; return true;} return false; }
#define INF 0x7FFFFFFF
#define LINF 0x7FFFFFFFFFFFFFFFLL
#define Yes(q) (q ? "Yes" : "No")
#define YES(q) (q ? "YES" : "NO")
#define DUMP(q) cerr << "[DEBUG] " #q ": " << (q) << " at " __FILE__ ":" << __LINE__ << endl
#define DUMPALL(q) { cerr << "[DEBUG] " #q ": ["; REP(dumpall_i, (q).size()) { cerr << q[dumpall_i] << (dumpall_i == (q).size() - 1 ? "" : ", "); } cerr << "] at " __FILE__ ":" << __LINE__ << endl; }
template<class T> T gcd(const T &a, const T &b) { return a < b ? gcd(b, a) : b ? gcd(b, a % b) : a; }
template<class T> T lcm(const T &a, const T &b) { return a / gcd(a, b) * b; }

// gcc拡張マクロ
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

// エイリアス
using  ll = long long;
using ull = unsigned long long;
using  ld = long double;
using namespace std;

// モジュール
ll ask(ll u, ll v) {
    cout << "? " << u << " " << v << endl;
    ll ans; cin >> ans;
    if (ans == -1) {
        exit(EXIT_FAILURE);
    } else {
        return ans;
    }
}

// 処理内容
int main() {
    
    ll n, s, t;
    cin >> n >> s >> t;

    vector<ll> froms(n+1, LINF); froms[s] = 0;
    vector<ll> fromt(n+1, LINF); fromt[t] = 0;

    RANGE(i, 1, n) if (i != s) {
        froms[i] = ask(s, i);
    }
    RANGE(i, 1, n) if (i != t) {
        fromt[i] = ask(t, i);
    }

    ll pl = froms[t]; // the length of the shortest path
    vector<ll> cand;
    RANGE(i, 1, n) {
        if (froms[i] + fromt[i] == pl) {
            cand.push_back(i);
        }
    }
    sort(ALL_OF(cand), [&](ll i, ll j) -> bool {
        return froms[i] < froms[j];
    });

    vector<ll> ans;
    for (ll i = 0; cand[i] != t; ) {

        ans.push_back(cand[i]);

        for (ll j = i+1; j < cand.size(); j++) {
            ll x = ask(cand[i], cand[j]);
            if (x == froms[cand[j]] - froms[cand[i]]) {
                i = j;
                break;
            }
        }

    }

    ans.push_back(t);

    cout << "! ";
    REP(i, ans.size()) cout << ans[i] << " \n"[i == i_len-1];
    
}
