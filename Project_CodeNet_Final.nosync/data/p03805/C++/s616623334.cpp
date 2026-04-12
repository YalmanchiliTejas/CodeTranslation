#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define sim template < class c
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
~debug() { cerr << endl; }
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
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 

int main(){
    fastio
    int n , m ; 
    cin >> n >> m; 
    vector<vector<int> > v(n, vector<int>(m));
    for(int i = 0; i < m; i++){
        int x , y ; 
        cin >> x >> y ; 
        x--, y--;
        v[x][y] = 1;
        v[y][x] = 1;
    }
    vector<int> a ; 
    for(int i = 1; i < n; i++){
        a.push_back(i);
    }
    int ans = 0 ;
    do{
        a.insert(a.begin(), 0);
        bool ok = true ;
        for(int i = 1; i < (int) a.size(); i++){
            if ( !v[a[i]][a[i - 1]] ) ok = false;
        }
        a.erase(a.begin());
        if ( ok ) ans++;
    }while(next_permutation(a.begin(),a.end()));
    cout << ans << endl;
    return 0 ;
}