#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ull = unsigned long long int;
using ll = long long int;
constexpr ull mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ull> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    ull sum = 0;
    ull state = 0;
    for (int i = n - 2; i >= 0; i--) {
        state += A[i + 1];
        state = state % mod;
        sum += state * A[i];
        sum = sum % mod;
    }

    cout << sum << endl;

    return 0;
}