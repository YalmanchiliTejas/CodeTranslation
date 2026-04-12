#include <bits/stdc++.h>

using namespace std;

template<typename T>
int longestIncreasingSubsequence(const std::vector<T> &a) {
    if (a.empty()) return {};

    const T INF = std::numeric_limits<T>::max();
    const int size = a.size();

    std::vector<T> dp(size, INF);
    std::vector<int> idx(size);
    for (int i = 0; i < size; ++i) {
        // 単調増加： a_i <= a_j
        idx[i] = std::distance(dp.begin(), upper_bound(dp.begin(), dp.end(), a[i]));
        dp[idx[i]] = a[i];
    }

    return *max_element(idx.begin(), idx.end()) + 1;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &a_i : a) cin >> a_i, a_i *= -1;

    cout << longestIncreasingSubsequence<int>(a) << endl;

    return 0;
}
