#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector< pair<int64_t,int64_t> > v(N);
    for(int i=0; i<N; i++) {
        int64_t a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        v[i] = make_pair(a, b);
    }

    sort(v.begin(), v.end());
    v.emplace_back(v.front().second, v.back().first);

    vector<int64_t> lmax(N+1), lmin(N+1), r(N+1);
    for(int i=0; i<=N; i++) {
        lmax[i] = v[i].second;
        lmin[i] = v[i].second;
        r[i] = v[i].second;
    }
    for(int i=1; i<=N; i++) {
        lmax[i] = max(lmax[i-1], lmax[i]);
        lmin[i] = min(lmin[i-1], lmin[i]);
    }
    for(int i=N-1; i>=0; i--) {
        r[i] = max(r[i], r[i+1]);
    }

    int64_t ans = numeric_limits<int64_t>::max();
    for(int i=0; i<N; i++) {
        int64_t R_min = v.front().first;
        int64_t R_max = r[i+1];
        int64_t B_min = min(v[i+1].first, lmin[i]);
        int64_t B_max = max(lmax[i], v[N-1].first);
        cerr << i << ' ' << R_min << ' ' << R_max << ' ' << B_min << ' ' << B_max << endl;
        ans = min(ans, (R_max - R_min) * (B_max - B_min));
    }

    cout << ans << endl;
    return 0;
}
