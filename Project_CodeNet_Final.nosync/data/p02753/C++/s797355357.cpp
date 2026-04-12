#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define LL       long long
#define DS       pair<LL, LL>
#define READ(f)  freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
//template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    string s;
    cin >> s;
    puts(s[0] == s[1] && s[1] == s[2] ? "No" : "Yes");
    return 0;
}
