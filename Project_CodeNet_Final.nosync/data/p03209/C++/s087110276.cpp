//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


inline void print() {
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest) {
    cout << first << ' ';
    print(rest...);
}


vector<long long> num, p;
long long ans = 0;

void rec(long long n, long long x) {
    if (x <= 0) return;

    if (x >= num[n] - 1) {
        ans += p[n];
        return;
    }

    if (x > num[n] / 2) {
        ans += p[n-1] + 1;
        x -= num[n-1] + 2;
        rec(n-1, x);
        return;
    }

    if (x <= num[n] / 2) {
        rec(n-1, x-1);
        return;
    }
}

void solve() {
    int N;
    long long X;
    cin >> N >> X;

    num.resize(N+1);
    p.resize(N+1);

    num[0] = 1; p[0] = 1;
    for (int i = 1; i < N+1; i++) {
        num[i] = num[i-1] * 2 + 3;
        p[i] = p[i-1] * 2 + 1;
    }

    rec(N, X);

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}