#include <bits/stdc++.h>
//#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define oo 0x3f3f3f3f
#define OO 0x3f3f3f3f3f3f3f3f
#define popcount(n) __builtin_popcount(n)
#define popcountll(n) __builtin_popcountll(n)

//bool flag = __builtin_add_overflow(a , b , &tmp);
//bool flag = __builtin_mul_overflow(a , b , &tmp);
//bool flag3= __builtin_sub_overflow(a , b , &tmp);

using namespace std;
//using namespace __gnu_cxx;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const double PI = acos(-1.0), EPS = 1e-6;
const long long inf = 2e12 + 12;
const int MAXN = 10004, MAXM = 102, Mod = 1000000007 , MAXLog = 20;



int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(9), cout << fixed;

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    multiset<int> last;
    for (int i = 0; i < n; i++) {
        multiset<int>::iterator it = last.lower_bound(arr[i]);
        if (it == last.begin())
            last.insert(arr[i]);
        else {
            it--;
            last.erase(it);
            last.insert(arr[i]);
        }
    }


    cout << last.size() << '\n';


    return 0;
}