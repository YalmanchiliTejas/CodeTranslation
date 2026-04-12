#include <bits/stdc++.h>
//#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define oo 0x3f3f3f3f
#define OO 0x3f3f3f3f3f3f3f3f
#define popcount(n) __builtin_popcount(n)
#define popcountll(n) __builtin_popcountll(n)

using namespace std;
//using namespace __gnu_cxx;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const double PI = acos(-1.0), EPS = 1e-6;
const long long inf = 2e12 + 12;
const int MAXN = 200005, MAXM = 3003, Mod = 1000000007 , MAXLog = 20;



int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i= 0 ; i < n; ++i) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        bool f = true;
        for (int j = 0; j < i; ++j) {
            f &= arr[j] <= arr[i];
        }
        ans += f;
    }
    
    cout << ans << '\n';

    return 0;
}