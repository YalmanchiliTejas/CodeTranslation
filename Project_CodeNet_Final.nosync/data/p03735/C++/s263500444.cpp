#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using int64 = int64_t;

constexpr int64 MOD = 1000000007;

constexpr int64 INF = 1LL<<60;

typedef pair<int64, int64> P;

int N;
int64 X[200000], Y[200000];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N; for (int j = 0; j < N; ++j) {
        cin >> X[j] >> Y[j];
        if (X[j] > Y[j]) swap(X[j], Y[j]);
    }

    vector<P> ps;
    for (int j = 0; j < N; ++j) ps.emplace_back(X[j], Y[j]);
    sort(begin(ps), end(ps));

    int64 bmin = INF, bmax = -INF;
    for (int j = 0; j < N; ++j) {
        bmin = min(bmin, ps[j].second);
        bmax = max(bmax, ps[j].second);
    }

    int64 ans = (bmax - bmin) * (ps[N-1].first - ps[0].first);
    
    bmin = ps[0].first; 
    int64 sndmin = ps[0].second, sndmax = ps[0].second;
    for (int j = 1; j < N; ++j) {
        ans = min(ans, (bmax - ps[0].first) * (max(sndmax, ps[N-1].first) - min(sndmin, ps[j].first)));

        sndmin = min(sndmin, ps[j].second);
        sndmax = max(sndmax, ps[j].second);
    }

    cout << ans << endl;
    return 0;
}
