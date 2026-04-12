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
const int INF = 2100100100;
// const int MOD = 1e9 + 7;
template <class T>
ostream &operator<<(ostream &s, vector<T> vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        if (i > 0) {
            s << ' ';
        }
        s << vec[i];
    }
    return s << endl;
}

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    ll ans = 0;
    sort(A.begin(), A.end(), greater<ll>());

    // cerr << A;

    while (A[0] - A[N - 1] >= N) {
        ll n = (A[0] - A[N - 1]) / N;
        ans += n;
        A[0] -= n * N;
        for (int i = 1; i < N; i++) {
            A[i] += n;
        }
        sort(A.begin(), A.end(), greater<ll>());
    }

    // cerr << A;

    ll num = A[N - 1] - (N - 1);
    if (num > 0) {
        for (int i = 0; i < N; i++) {
            A[i] -= num;
        }
        ans += num * N;
    }

    //cerr << A;

    while (1) {
        sort(A.begin(), A.end(), greater<ll>());
        if (A[0] <= N - 1) break;
        A[0] -= N;
        for (int i = 1; i < N; i++) {
            A[i]++;
        }
        ans++;
    }
    cout << ans << endl;
}
