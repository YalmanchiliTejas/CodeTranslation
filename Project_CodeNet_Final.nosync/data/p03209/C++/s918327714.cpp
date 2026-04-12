#include "bits/stdc++.h"
using namespace std;


long long f(int N, long long X) {
    vector<long long> sum = {1};
    vector<long long> pat = {1};
    for (int i = 0; i < N; i++) {
        sum.push_back(sum[i] * 2 + 3);
        pat.push_back(pat[i] * 2 + 1);
    }
    if (N == 0) {
        if (X <= 0) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else if (X <= 1 + sum[N - 1]) {
        return f(N - 1, X - 1);
    }
    else {
        return pat[N - 1] + 1 + f(N - 1, X - 2 - sum[N - 1]);
    }
}

int main() {
    int N;
    cin >> N;
    long long X;
    cin >> X;
    cout << f(N, X) << endl;
}
