#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 53;

long long N, K;
vector<long long> meat;
vector<long long> num;

void input() {
    cin >> N >> K;
    meat.resize(MAX_N); meat[0] = 1;
    num.resize(MAX_N);  num[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        meat[i] = 1 + meat[i-1] * 2;
        num[i] = 3 + num[i-1] * 2;
    }
    return;
}

long long func(long long Lv, long long X) {
    if (X == 0) return 0LL;
    if (Lv == 0) return meat[0];
    if (X == 1) return 0LL;
    if (X == num[Lv]) return meat[Lv];
    long long half = num[Lv-1]+2;
    if (half <= X) return meat[Lv-1] + 1 + func(Lv-1, X-half);
    return func(Lv-1, X-1);
}

int main() {
    input();
    long long ans = func(N, K);
    cout << ans << endl;
    return 0;
}