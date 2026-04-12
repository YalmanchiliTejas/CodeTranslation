#include <iostream>
#include <set>
#include <vector>
#include <utility>
using namespace std;

using int64 = long long;

int main() {
    int N;
    cin >> N;

    vector<int64> x(N), y(N);
    int64 rmax = 0,
          rmin = (1LL << 40),
          bmax = 0,
          bmin = (1LL << 40);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        rmax = max(rmax, max(x[i], y[i]));
        rmin = min(rmin, max(x[i], y[i]));
        bmax = max(bmax, min(x[i], y[i]));
        bmin = min(bmin, min(x[i], y[i]));
    }

    int64 ans = (rmax - rmin) * (bmax - bmin);

    rmin = min(rmin, bmin);

    set<pair<int64, int>> st;
    for (int i = 0; i < N; i++) st.insert({min(x[i], y[i]), i});
    while (!st.empty()) {
        int64 diff = st.rbegin()->first - st.begin()->first;
        ans = min(ans, (rmax - rmin) * diff);

        auto elt = *st.begin();
        if (elt.second >= 364364) break;
        st.insert({max(x[elt.second], y[elt.second]), 364364});

        st.erase(elt);
    }
    cout << ans << endl;

    return 0;
}