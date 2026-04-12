#include <bits/stdc++.h>
using namespace std;
#define INF 9223372036854775807

int64_t rf(vector<vector<int64_t> > &dp, vector<int64_t> &a, int i, int j) {
    if (dp.at(i).at(j) != INF) {
        return dp.at(i).at(j);
    }
    if (i == j) {
        return a.at(i);
    }
    dp.at(i).at(j) = max(a.at(i) - rf(dp, a, i+1, j), a.at(j) - rf(dp, a, i, j-1));
    return dp.at(i).at(j);
}

int main() {
    int n; cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    vector<vector<int64_t> > dp(n, vector<int64_t>(n, INF));
    cout << rf(dp, a, 0, n-1) << endl;
}