#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#ifdef _DEBUG_
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl
#else
#define dump(val)
#endif

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

template<typename T>
void chmax(T &a, T b) {
    a = max(a, b);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> V(n + 1, 0);
    REP(i, 0, n) {
        cin >> V[i + 1];
        V[i + 1] += V[i];
    }
    int ans = 0;
    map<ll, int> m;
    REP (i, 0, n + 1) {
        if (m.count(V[i])) {
            chmax(ans, i - m[V[i]]);
        } else {
            m[V[i]] = i;
        }
    }
    cout << ans << endl;
    return 0;
}

