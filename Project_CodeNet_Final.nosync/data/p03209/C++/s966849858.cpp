#include <bits/stdc++.h>
using namespace std;

long long p[51], b[51];

long long pate(int i) {
    if (i == 0) return 1;
    return p[i] = 2 * pate(i - 1) + 1;
}

long long burger(int i) {
    if (i == 0) return 1;
    return b[i] = 2 * burger(i - 1) + 3;
}

long long calc(int i, long long x) {
    if (x == 1) {
        if (i == 0)
            return 1;
        else
            return 0;
    } else if (b[i] == x) {
        return p[i];
    } else if (b[i] / 2 + 1 > x) {
        return calc(i - 1, x - 1);
    } else if (b[i] / 2 + 1 == x) {
        return p[i] / 2 + 1;
    } else {
        return (p[i] / 2 + 1) + calc(i - 1, x - (b[i] / 2 + 1));
    }
}

int main() {
    int N;
    long long X;
    cin >> N >> X;
    pate(N);
    burger(N);
    cout << calc(N, X) << endl;
}