#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int MAX = 3000;
int N, A[MAX];
bool vis[MAX][MAX + 1];
ll memo[MAX][MAX + 1];

ll dp(int L, int R) {
    if (L >= R) return 0;
    if (vis[L][R]) return memo[L][R];
    vis[L][R] = true;

    int diff = N - (R - L);

    ll res = 0;
    if (diff % 2 == 0) {
        res = max(dp(L + 1, R) + A[L], dp(L, R - 1) + A[R - 1]);
    } else {
        res = min(dp(L + 1, R) - A[L], dp(L, R - 1) - A[R - 1]);
    }
    return memo[L][R] = res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];

    cout << dp(0, N) << endl;
    return 0;
}