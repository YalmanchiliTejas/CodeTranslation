#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A) cin >> x;
    reverse(A.begin(), A.end());

    vector<int> LIS(N, INT_MAX);
    for (auto &x : A) {
        *upper_bound(LIS.begin(), LIS.end(), x) = x;
    }

    cout << lower_bound(LIS.begin(), LIS.end(), INT_MAX) - LIS.begin() << endl;

    return 0;
}