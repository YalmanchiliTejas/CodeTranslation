#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define sim template < class c
#define int long long
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << '\n'; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
typedef tree< pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    int k = 3 ;
    auto fix = [&](int x){
        return (x % n + n) % n ;
    };
    for(int mask = 0; mask < (1 << k); mask++){
        string st ;
        for(int i = 0; i < k; i++){
            if ( (1LL << i) & mask ) {
                st.push_back('S') ;
            }
            else st.push_back('W') ;
        }
        vector<char> ans(n) ;
        ans[n - 1] = st[0] ;
        ans[0] = st[1] ;
        ans[1] = st[2] ; 
        for(int i = 1; i < n - 1; i++){
            if ( ans[i] == 'S' ){
                if ( s[i] == 'o' ) {
                    ans[i + 1] = ans[i - 1] ;
                }
                else{
                    if ( ans[i - 1] == 'W' ) ans[i + 1] = 'S' ;
                    else ans[i + 1] = 'W' ;
                }
            }
            else {
                if ( s[i] == 'x' ){
                    ans[i + 1] = ans[i - 1] ;
                }
                else {
                    if ( ans[i - 1] == 'W' ) ans[i + 1] = 'S' ;
                    else ans[i + 1] = 'W' ;
                }
            }
        }
        bool ok = true ;
        for(int i = 0; i < n; i++){
            int a = fix(i - 1) ;
            int b = fix(i + 1) ;
            if ( ans[i] == 'S' ) {
                if ( s[i] == 'o' ) {
                    if ( ans[a] != ans[b] ) {
                        ok = false ;
                        break ;
                    }
                }
                else{
                    if ( ans[a] == ans[b] ) {
                        ok = false ;
                        break ;
                    }
                }
            }
            else{
                if ( s[i] == 'x' ) {
                    if ( ans[a] != ans[b] ) {
                        ok = false ;
                        break ;
                    }
                }
                else{
                    if ( ans[a] == ans[b] ) {
                        ok = false ;
                        break ;
                    }
                }
            }
        }
        if ( ok ) {
            for(char &c : ans){
                cout << c ;
            }
            cout << endl;
            return 0 ;
        }
    }
    cout << -1 << endl;
    return 0; 
}