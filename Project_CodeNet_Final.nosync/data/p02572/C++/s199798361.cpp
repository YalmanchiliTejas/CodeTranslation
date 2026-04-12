// AtCoder :: Beginner Contest 177 :: C - Sum of product of pairs 
// https://atcoder.jp/contests/abc177/tasks/abc177_c

// REF: https://www.geeksforgeeks.org/sum-product-pairs-array-elements/
// (a + b + c + ..)^2 = (a^2 + b^2 + c^2 ... + 2 * (a*b + b*c ...))

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD{1000000007};

ll pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;

    if (base == 0) return 0;

    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }

        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<ll> arr;
    arr.reserve(N);
    copy_n(istream_iterator<int>(cin), N, back_inserter(arr));

    // Compute sum of array.
    ll arraySum{0};
    for (int i{0}; i < N; ++i) {
        arraySum = (arraySum + arr[i]) % MOD;
    }

    // Compute (a + b + c ...)^2
    ll arraySumSquared = (arraySum * arraySum) % MOD;

    // Compute sum of individual squares
    ll individualSquaresSum{0};
    for (int i{0}; i < N; ++i) {
        ll sq = (arr[i] * arr[i]) % MOD;
        individualSquaresSum = (individualSquaresSum + sq) % MOD;
    }

    // Mod inverse of 2.
    ll modInv2{pow(2, MOD-2, MOD)};

    // Solution
    ll a = (arraySumSquared - individualSquaresSum) % MOD;
    if (a < 0) {
        a += MOD;
    }
    ll soln{(a * modInv2) % MOD};
    cout << soln << "\n";
    return EXIT_SUCCESS;
}
