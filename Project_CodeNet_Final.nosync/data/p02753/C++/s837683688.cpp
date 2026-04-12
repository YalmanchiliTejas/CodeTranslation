#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;

#ifdef DEBUG
#define IO
#else
#define IO ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define cerr
#endif
#define _ <<' '<<
#define Fr(i, s, e) for(auto i = s; i < e; ++i)
#define Ft first
#define Sd second
#define All(v) v.begin(),v.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
// template<typename T> using rkt = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() {
    IO;

    string s;
    cin >> s;
    sort(All(s));
    cout << ((unique(All(s))-s.begin())==2 ? "Yes" : "No") << endl;
 
}