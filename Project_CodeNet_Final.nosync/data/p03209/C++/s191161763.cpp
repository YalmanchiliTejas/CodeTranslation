#include "bits/stdc++.h"

using namespace std;

long long numPatty(long long level) {
    if (level == 0) {
        return 1;
    }
    else {
        return 2 * numPatty(level - 1) + 1;
    }
}

long long numLayer(long long level) {
    if (level == 0) {
        return 1;
    }
    else {
        return 2 * numLayer(level - 1) + 3;
    }
}

long long solve(long long n, long long x) {
    if (n == 0) {
        return 1;
    }

    long long nlayer = numLayer(n);
    if (x == 0) {
        return 0;
    }
    else if (x == (nlayer - 1) / 2) {
        return numPatty(n - 1) + 1;
    }
    else if (x == nlayer - 1) {
        return 2 * numPatty(n - 1) + 1;
    }
    else if (0 < x && x < (nlayer - 1) / 2) {
        return solve(n - 1, x - 1);
    }
    else { // (nlayer - 1) / 2 < x && x < nlayer - 1
        return numPatty(n - 1) + 1 + solve(n - 1, x - (nlayer - 1) / 2 - 1);
    }
}

void Main() {
    long long  N, X;
    cin >> N >> X;

    long long ans = solve(N, X - 1);
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
