#pragma GCC optimize ("O3")
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <bitset>
#include <cstdio>

using namespace std;
using namespace std::placeholders;

// namespace { struct NoSync { NoSync() { cin.tie(0); ios::sync_with_stdio(false); } } nosync; }

using ll = long long;
#define float double

#define cauto const auto

constexpr ll INF = 999999999LL;
constexpr ll MOD = 1e9 + 7;

#define y0 Y0
#define y1 Y1
#define j0 J0
#define j1 J1
#define prev PREV
#define next NEXT

#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i##_len = (n), i = (i##_len) - 1; i >= 0; i--)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define permutations(v) sort(all(v));for(bool v##p = true; v##p; v##p=next_permutation(all(v)))
#define UNIQUE(v) (v).erase(unique(all(v)), (v).end())
#define REMOVE(v) (v).erase(remove(all(v)), (v).end())
#define ROTATE(v, n) rotate((v).begin(), (v).begin() + (n), (v).end())
#define TO_SUMS(v) partial_sum(all(v), (v).begin())
#define SUMS(srcv, dstv) partial_sum(all(srcv), (dstv).begin())
#define nth_bit(n) (1LL<<(n))

template <typename T> T high()  { return numeric_limits<T>::max(); }
template <typename T> T high(T) { return numeric_limits<T>::max(); }
template <typename T> T low()   { return numeric_limits<T>::lowest(); }
template <typename T> T low(T)  { return numeric_limits<T>::lowest(); }

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

// f には functional のオブジェクトが便利 (lambda 式も   [](int a){ return a / 2 }   みたいな)
template<class C, class F> inline C mapped(const C& c, F f){// mapっていうSTLがあるから...
    // ex: mapped(v, bind(plus<ll>(), _1, 2))   [v の各要素について x + 2]
    C r; r.reserve(c.size()); transform(all(c), back_inserter(r), f); return r;
}
template<class C, class F> inline C filtered(const C& c, F f){
    // ex: filtered(v, bind(equal_to<ll>(), bind(modulus<ll>(), _1, 2), 0)   [x mod 2 == 0 な x を取ってくる]
    C r; copy_if(all(c), back_inserter(r), f); return r;
}
template<class C, class I, class F> inline typename C::value_type foldl(const C& c, I i, F f){
    // ex: foldl(v, 1, multiplies<int>())   [v の総乗]
    return accumulate(all(c), static_cast<typename C::value_type>(i), f);
}

// 出力
template<class T> ostream& operator << (ostream &s, vector<T> v){
    rep(i, v.size()) { if (i != 0) { s << " "; } s << v[i]; } return s;
}
template<class T, class U> ostream& operator << (ostream &s, pair<T, U> p){
    return s << p.first << " " << p.second;
}


int main(){
    ll N; cin >> N;
    vector<ll> A(N); rep(i, N) cin >> A[i];

    multiset<ll> s;

    for(ll i = N - 1; i >= 0; i--){
        if(s.size() == 0) s.insert(A[i]);
        else{
            cauto ui = s.upper_bound(A[i]);
            ll u = *ui;
            if(ui == s.end()) s.insert(A[i]);
            else{
                s.erase(ui);
                s.insert(A[i]);
            }
        }
    }

    cout << s.size() << endl;

    return 0;
}
