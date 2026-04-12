#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}

int main() {
    int A, B, C;
    long long X, Y;
    cin >> A >> B >> C >> X >> Y;
    // AをX枚
    // BをY枚
    if(A + B <= 2 * C) {
        cout << X * A + Y * B << endl;
        return 0;
    } else {
        long long m = min(X, Y);
        long long res = 0;
        res += 2 * m * C;
        res += A * (X - m);
        res += B * (Y - m);
        if(res <= 2 * max(X, Y) * C) {
            cout << res << endl;
            return 0;
        } else {
            cout << 2 * max(X, Y) * C << endl;
        }
        return 0;
    }
}