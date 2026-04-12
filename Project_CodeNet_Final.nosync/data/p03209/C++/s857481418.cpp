#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl

using namespace std;

typedef long long int ll;

template<typename T>
vector<T> make_v(size_t a, T b) {
    return vector<T>(a, b);
}

template<typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> AL(N + 1), PA(N + 1);
    AL[0] = PA[0] = 1;
    REP(i, 0, N) {
        AL[i + 1] = 2 * AL[i] + 3;
        PA[i + 1] = 2 * PA[i] + 1;
    }
    function<ll(int, ll)> rec = [&](int n, ll x) {
        if (n == 0) {
            return 1LL;
        }
        if (x == 1) {
            return 0LL;
        }
        if (x <= AL[n - 1] + 2) {
            return rec(n - 1, x - 1) + (x == AL[n - 1] + 2);
        }
        return rec(n - 1, x - AL[n - 1] - 2) + PA[n - 1] + 1;
    };

    cout << rec(N, X) << endl;
    return 0;
}
