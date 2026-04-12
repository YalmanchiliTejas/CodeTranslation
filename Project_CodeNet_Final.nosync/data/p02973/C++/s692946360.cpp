#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    reverse(a.begin(), a.end());

    vector<int> dp;
    dp.push_back(a[0]);

    rep1(i, n){
        if(a[i] >= dp.back()) dp.push_back(a[i]);
        else{
            int idx = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[idx] = a[i];
        }
        // rep(i, dp.size()) cout << dp[i] << " ";
        // cout << endl;
    }

    cout << dp.size() << endl;

    return 0;
}