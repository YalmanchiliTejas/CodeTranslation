#include <bits/stdc++.h>
using namespace std;

template<class T> int LIS(vector<T> a,  bool is_strong = true) {
    const T INF = 1<<30; // to be set appropriately
    int n = (int)a.size();
    vector<T> dp(n, INF);
    for (int i = 0; i < n; ++i) {
        if (is_strong) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        else *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}


int main() {
    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i], a[i] *= -1;
    cout << LIS(a, false) << endl;
}
