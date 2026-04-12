#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i] *= -1;
    }

    int INF = (1<<30);
    // A についての広義単調減少列の最大の長さを求めればよい
    // A * (-1) についての広義単調増加列にすればよい
    vector<int> dp(n, INF);
    for(int i=0; i<n; i++){
        auto itr = upper_bound(dp.begin(), dp.end(), a[i]);
        int ind = distance(dp.begin(), itr);
        dp[ind] = a[i];
    }

    auto itr = lower_bound(dp.begin(), dp.end(), INF);
    int ind = distance(dp.begin(), itr);
    cout << ind << endl;

    return 0;
}