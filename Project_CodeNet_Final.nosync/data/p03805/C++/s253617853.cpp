#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 1e9;
// const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    auto G = make_vec<int>(N, N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a][b] = 1;
        G[b][a] = 1;
    }

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = i;
    }

    long long ans = 0;
    do {
        if (A[0] != 0) break;
        bool flag = true;
        for (int i = 0; i < N - 1; i++) {
            if (G[A[i]][A[i + 1]] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) ans++;
    } while (next_permutation(A.begin(), A.end()));
    cout << ans << endl;
}
