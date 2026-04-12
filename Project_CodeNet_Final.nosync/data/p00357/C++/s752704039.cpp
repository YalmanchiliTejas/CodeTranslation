#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr int INF = 1e9;
constexpr ll INFLL = 1e18;

int main() {
    int N; cin >> N;
    vector<int> x(N), rx;
    for(int i = 1; i < N; ++i) {
        x[i] = 10 + x[i - 1];
    }
    rx = x;
    vector<int> d(N);
    for(int i = 0; i < N; ++i) {
        cin >> d[i];
    }
    for(int i = 0; i < N; ++i) {
        x[i] += d[i];
        rx[i] += d[N - i - 1];
    }

    bool ans = true;
    int last = 1;
    for(int i = 0; i < last; ++i) {
        last = min(N, max(last, x[i] / 10 + 1));
    }
    ans &= last == N;
    last = 1;
    for(int i = 0; i < last; ++i) {
        last = min(N, max(last, rx[i] / 10 + 1));
    }
    ans &= last == N;

    if(ans) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}
