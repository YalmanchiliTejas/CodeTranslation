#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

int main() {
    ll N, X, M;
    cin >> N >> X >> M;
    map<ll, bool> used; used[X] = true;
    vector<ll> loop = {X};
    ll before = X;
    while (true) {
        before = before * before % M;
        if (used[before]) break;
        loop.push_back(before);
        used[before] = true;
    }

    int start_i = 0;
    REP(i, loop.size()) {
        if (loop[i] == before) {
            start_i = i;
            break;
        }
    }

    ll ans = 0;
    if (N <= loop.size()) {
        REP(i, N) ans += loop[i];
        cout << ans << endl;
        return 0;
    }

    REP(i, start_i) ans += loop[i];
    N -= start_i;
    int loop_size = loop.size() - start_i;
    ll sum = 0;
    FOR(i, start_i, loop.size()) {
        sum += loop[i];
    }
    ans += sum * (N / loop_size);
    REP(i, N % loop_size) {
        ans += loop[start_i + i];
    }
    cout << ans << endl;
    return 0;
}