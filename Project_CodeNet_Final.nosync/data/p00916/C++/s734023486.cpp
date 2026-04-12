#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#include <map>
template<typename T> struct Compress1D {
    map<T, int> zip; vector<T> unzip; int sz;
    Compress1D(vector<T> a) {
        sort(begin(a), end(a)); a.erase(unique(begin(a), end(a)), end(a));
        sz = a.size(); unzip.resize(sz);
        for (int i = 0; i < sz; i++) zip[a[i]] = i, unzip[i] = a[i];
    }
    int operator[](T x) { return zip[x]; }
    T inv(int idx) { return unzip[idx]; }
    int size() { return sz; }
};

int main() {
    int n;
    while (cin >> n, n) {
        vector<int> l(n), b(n), r(n), t(n);
        for (int i = 0; i < n; i++) cin >> l[i] >> t[i] >> r[i] >> b[i];
        vector<int> xx, yy;
        xx.insert(xx.end(), l.begin(), l.end());
        yy.insert(yy.end(), t.begin(), t.end());
        xx.insert(xx.end(), r.begin(), r.end());
        yy.insert(yy.end(), b.begin(), b.end());
        xx.emplace_back(-1); xx.emplace_back(1e9);
        yy.emplace_back(-1); yy.emplace_back(1e9);
        Compress1D<int> compX(xx), compY(yy);
        int sx = compX.size(), sy = compY.size();
        using ll = long long;
        vector<vector<ll>> xy(sx, vector<ll>(sy));
        for (int i = 0; i < n; i++) {
            l[i] = compX[l[i]], r[i] = compX[r[i]];
            b[i] = compY[b[i]], t[i] = compY[t[i]];
            for (int x = l[i]; x < r[i]; x++) {
                for (int y = b[i]; y < t[i]; y++) {
                    xy[x][y] |= 1LL << i;
                }
            }
        }
        int dxy[] = {0, 1, 0, -1, 0};
        auto dfs = [&](auto dfs, int x, int y, ll cur) -> void {
            xy[x][y] = -1;
            for (int k = 0; k < 4; k++) {
                int nx = x + dxy[k], ny = y + dxy[k + 1];
                if (nx < 0 || nx >= sx || ny < 0 || ny >= sy) continue;
                if (xy[nx][ny] == cur) dfs(dfs, nx, ny, cur);
            }
        };
        int cnt = 0;
        for (int x = 0; x < sx; x++) for (int y = 0; y < sy; y++) {
            if (~xy[x][y]) dfs(dfs, x, y, xy[x][y]), cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
