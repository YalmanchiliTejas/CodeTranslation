#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ull  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 1100000;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if (k == 0){
        cout << n * n;
        return 0;
    }
    for (int i = k + 1; i <= n; i++){
        int f = n % i;
        if (f >= k) ans += f - k + 1;
        int m = n - f;
        int x = i - k;
        ans += m / i * x;
    }
    cout << ans;
}
