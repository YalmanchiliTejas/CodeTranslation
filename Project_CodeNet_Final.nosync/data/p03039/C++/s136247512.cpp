#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include<iomanip>
using namespace std;

int N, M;
long long K;

int mod = 1e9 + 7;

int power(int a, int n){
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        int b = power(a, n / 2);
        return 1ll * b * b % mod;
    } else {
        return 1ll * a * power(a, n - 1) % mod;
    }
}

int inverse(int a) {
    if (a == 1) {
        return 1;
    }
    return power(a, mod - 2);
}

int main() {
    cin >> N >> M >> K;
    int nmr = 1, dnm1 = 0, dnm2 = 0;
    int tmp = 1;
    for (long long i = 1; i < 1ll * N * M - 1; i++) {
        tmp = 1ll * tmp * i % mod;
        if (i == N * M - 2) nmr = tmp;
        else if (i == K - 2) dnm1 = tmp;
        else if (i == N * M - K) dnm2 = tmp;
    }
    long long ans = 0;
    for (int d = 0; d < M; d++) {
        ans += 1ll * (M - d) * d % mod * N % mod * N % mod;
        ans %= mod;
    }
    for (int d = 0; d < N; d++) {
        ans += 1ll * (N - d) * d % mod * M % mod * M % mod;
        ans %= mod;
    }
    if (1ll * dnm1 * dnm2 > 0) {
        ans *= 1ll * nmr * inverse(dnm1) % mod * inverse(dnm2) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}
