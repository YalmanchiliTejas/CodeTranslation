#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define INF (INT64_MAX /2)


























int main() {
    long long N, X, M;
    cin >> N >> X >> M;
    long long ans = 0;
    for (int i = 0; i < 20; i++) {
        ans += X;
        X = (X * X) % M;
        N--;
        if (N == 0) break;
    }
    vector<long long> period;
    period.push_back(X);
    X = (X * X) % M;
    while(X != period[0]) {
        period.push_back(X);
        X = (X * X) % M;
    }
    long long q = N / period.size();
    long long sum = 0;
    for (long long i: period) {
        sum += i;
    }
    long long sum2 = 0;
    for (long long i = 0; i < (N % period.size()); i++) {
        sum2 += period[i];
    }
    ans += sum * q + sum2;

    cout << ans << endl;
}