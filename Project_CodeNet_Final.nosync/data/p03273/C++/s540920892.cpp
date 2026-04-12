#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl

using namespace std;

typedef long long int lli;

template<typename T>
vector<T> make_v(size_t a, T b) {
    return vector<T>(a, b);
}

template<typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

int main() {
    int H, W;
    cin >> H >> W;
    auto mp = make_v(H, W, ' ');
    REP(i, 0, H) {
        REP(j, 0, W) {
            cin >> mp[i][j];
        }
    }
    vector<bool> isPrintH(H, false), isPrintW(W, false);
    REP(i, 0, H) {
        REP(j, 0, W) {
            isPrintH[i] = isPrintH[i] | (mp[i][j] == '#');
            isPrintW[j] = isPrintW[j] | (mp[i][j] == '#');
        }
    }
    REP(i, 0, H) {
        if (!isPrintH[i]) continue;
        REP(j, 0, W) {
            if (!isPrintW[j]) continue;
            cout << mp[i][j];
        }
        cout << endl;
    }
    return 0;
}
