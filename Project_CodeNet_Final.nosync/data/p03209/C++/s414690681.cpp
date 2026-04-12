#include <bits/stdc++.h>

using namespace std;

#define REP(var, n)  for (decltype(n) var = 0; var < (n); var++)
#define RREP(var, n)  for (auto var = n - 1; var != static_cast<decltype(var)>(-1); var--)
#define FOR(var, a, b)  for (auto var = (a); var < (b); var++)
#define RFOR(var, a, b)  for (auto var = b - 1; var != a; var--)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define all(c) begin(c),end(c)

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

const int INF = 1 << 29;

auto solve() {
    int N;
    ll X;
    cin >> N >> X;
    vll lens(51, 0), ps(51, 0);
    lens[0] = ps[0] = 1;
    FOR(i, 1, 51) {
        lens[i] = lens[i - 1] * 2 + 3;
        ps[i] = ps[i - 1] * 2 + 1;
    }
    function<ll(ll, int)> rec = [&](ll v, int depth) {
        ll half = lens[depth] / 2;
        if(depth==0) {
            return 1ll;
        } else if (v == 0) {
            return 0ll;
        } else if (v == lens[depth] - 1) {
            return ps[depth - 1] * 2 + 1;
        } else if (v == half) {
            return ps[depth - 1] + 1;
        } else if (v < half) {
            return rec(v - 1, depth - 1);
        } else {
            return ps[depth - 1] + 1 + rec(v - half - 1, depth - 1);
        }
    };

    return rec(X - 1, N);
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cout << solve() << endl;
//    solve();
    return 0;
}
