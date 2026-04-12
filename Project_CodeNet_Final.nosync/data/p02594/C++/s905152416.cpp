#include <bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
*/
#define fast            ios_base::sync_with_stdio(false)
#define mems(x, y)      memset(x, y, sizeof x)
#define pii             pair < int, int >
#define prec(x)         << fixed << setprecision(x)
#define itf             it->first
#define its             it->second
#define it(x)           it = x.begin(); it != x.end(); it++
#define pq_max(x)       priority_queue < x >
#define pq_min(x)       priority_queue < x, vector < x >, greater < x > >
#define ll              long long
#define nl              << "\n"
#define spc             << " "
#define pb              push_back
#define inf             0x3f3f3f3f
#define PI              3.14159265358979323846
#define E               2.71828182845904523536
#define gamma           0.5772156649
#define EPS             1e-9
#define toint(st, x)    stringstream ss(st); ss >> x
// =======Debug========//
#define watch(x)        cout << (#x) spc << x nl

int main()
{
    int n;
    cin >> n;
    if(n >= 30)     cout << "Yes\n";
    else    cout << "No\n";
    return 0;
}