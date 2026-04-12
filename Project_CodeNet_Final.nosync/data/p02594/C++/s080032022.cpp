#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;

#define rep(i, n) for (ll i = 0; i < ll(n); i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    if(x >= 30) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}