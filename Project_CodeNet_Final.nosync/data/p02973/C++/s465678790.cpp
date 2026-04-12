#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> dp;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        auto itr = lower_bound(dp.rbegin(), dp.rend(), A);
        if (itr == dp.rbegin())
            dp.push_back(A);
        else
            *(itr - 1) = A;
    }

    cout << dp.size() << endl;
    return 0;
}
