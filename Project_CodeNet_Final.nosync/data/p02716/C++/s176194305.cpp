#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 300000;
const int mod = 1e9 + 7;
const int K = 60;
const int M = 16;
int a[N], pr[N][2], suf[N][2];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i + i <= n; i++){
        pr[i][0] = pr[i - 1][0] + a[2 * i - 1];
        pr[i][1] = max(pr[i - 1][1] + a[2 * i], pr[i - 1][0] + a[2 * i]);
    }
    for (int i = 1; i + i <= n; i++){
        suf[i][0] = suf[i - 1][0] + a[n - 2 * i + 2];
        suf[i][1] = max(suf[i - 1][1] + a[n - 2 * i + 1], suf[i - 1][0] + a[n - 2 * i + 1]);
    }
    if (n % 2 == 0){
        cout << max(pr[n / 2][0], pr[n / 2][1]);
        return 0;
    }
    int ans = -2e18;
    for (int i = 1; i <= n; i += 2){
        int l = max(pr[i / 2][0], pr[i / 2][1]);
        int r = max(suf[(n - i) / 2][0], suf[(n - i) / 2][1]);
        ans = max(ans, l + r);
    }
    cout << ans;
}
