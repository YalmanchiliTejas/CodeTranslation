#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define MP make_pair
#define PB push_back
#define X first
#define Y second

typedef long long int lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 0;
    cin >> n;
    vector<lld> v(n);

    for (lld &x : v) {
        cin >> x;
    }

    lld sum = accumulate(v.begin(), v.end(), 0LL);
    lld ans = 0;
    lld mod = (lld) 1e9 + 7;

    for (int i = 0; i < n ; i++) {
        sum -= v[i];
        lld t = v[i] * (sum % mod) % mod;
        ans = (ans + t) % mod;
    }

    cout << ans % mod << '\n';

    return 0;
}

// g++ sol.cpp -o sol.out -Wall -Wextra -Wshadow -fsanitize=undefined -std=c++17