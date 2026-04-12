#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    vector<int> dp(n, -1);
    rep(i, n){
        *(--lower_bound(dp.begin(), dp.end(), a[i])) = a[i];
    }
    int ans = n - (lower_bound(dp.begin(), dp.end(), 0) - dp.begin());
    cout << ans << endl;
}