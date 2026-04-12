#include<bits/stdc++.h>
#define fl(i,a,n)      for(int i=a;i<=n;i++)
#define pb             push_back
#define int            long long int
#define ump            unordered_map
#define pii            pair<int,int>
#define ff             first
#define ss             second
#define PI             3.1415926535898
#define inf            1e18
#define vi             vector<int>
#define endl           "\n"
#define print(a)       for(auto x:a){cout<<x<<" ";}cout<<endl;
#define mod            1000000007
using namespace std;
template <typename Arg, typename... Args>
void db(Arg&& arg, Args&&... args) {
    cout << std::forward<Arg>(arg);
    using expander = int[];
    (void)expander{0, (void(cout << ',' << std::forward<Args>(args)), 0)...}; cout << endl;
}
inline int mymod(int A, int M) {return ((A % M) + M) % M;}
inline void solve() {
    int n; cin >> n;
    vi a(n);
    int sum = 0;
    fl(i, 0, n - 1) {
        cin >> a[i];
        sum += mymod(a[i], mod);
        sum = mymod(sum, mod);
    }
    int ans = 0;
    fl(i, 0, n - 1) {
        sum -= mymod(a[i], mod);
        sum = mymod(sum, mod);
        int temp = mymod(a[i], mod) * mymod(sum, mod);
        temp = mymod(temp, mod);
        ans += temp;
        ans = mymod(ans, mod);
    }
    ans = mymod(ans, mod);
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   //freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    fl(i, 1, t)
    {
        solve();
    }

    return 0;
}