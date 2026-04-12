#include <bits/stdc++.h>
#define ll long long
#define BUF 1e5
#define INF 1 << 30
constexpr ll mod = 1e9 + 7;
using namespace std;
ll A, B, C, D, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;
ll ans = 0;

int main() {
    cin >> N;
    vector<int> a(N);
    vector<int> mem;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    mem.push_back(a[0]);
    for (int i = 1; i < N; i++) {
        auto it = lower_bound(mem.rbegin(), mem.rend(), a[i]);
        int ind = mem.rend() - it - 1;
        if (ind == mem.size() - 1) {
            mem.push_back(a[i]);
        } else {
            mem[ind + 1] = a[i];
        }
    }
    cout << mem.size() << endl;
}