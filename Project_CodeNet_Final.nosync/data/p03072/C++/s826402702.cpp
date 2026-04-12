#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
 
#define pb push_back
#define mp make_pair

typedef long long ll; 

#define fi first
#define se second
 
#define all(x) (x).begin(), (x).end()
 
using namespace std;             
//using namespace __gnu_pbds;
 
//template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int INF = (int)1e10;                   

void solve() {                           
    int n;
    cin >> n;
    vector<int> a(n);int ans = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        ans += (mx <= a[i]);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt = 1;
 
    while (tt--) {
        solve();
    }
 
    return 0;
}