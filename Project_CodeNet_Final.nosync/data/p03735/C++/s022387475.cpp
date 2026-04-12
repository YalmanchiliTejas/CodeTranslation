#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N;
    cin >> N;
    vector<pair<ll, ll>> P(N);
    
    ll mi = 1e10, ma = 0, mi_index, ma_index; 
    for (int i = 0; i < N; i++) {
        ll X, Y;
        scanf("%lld %lld", &X, &Y);
        if (X > Y) swap(X, Y);
        P[i] = {X, Y};
    }
    sort(P.begin(), P.end());
    mi = P[0].first;
    mi_index = 0;
    
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (N == 2) {
        cout << min(abs((P[0].first-P[1].first)*(P[0].second-P[1].second)), abs((P[0].first-P[1].second)*(P[0].second-P[1].first)));
        return 0;
    }
    
    for (int i = 0; i < N; i++) {
        if (ma <= P[i].second) {
            ma = P[i].second;
            ma_index = i;
        }
    }
    if (mi == ma) {
        cout << 0 << endl;
        return 0;
    }
    
    ll cand1, cand2;
    ll rmin = mi, rmax = mi, bmax = ma, bmin = ma;
    for (int i = 0; i < N; i++) {
        rmax = max(rmax, P[i].first);
        bmin = min(bmin, P[i].second);
    }
    cand1 = (rmax-rmin)*(bmax-bmin);
    
    if (mi_index == ma_index) {
        cout << cand1 << endl;
        return 0;
    }
    
    rmin = mi; rmax = ma;
    bmin = min(P[mi_index].second, P[ma_index].first);
    bmax = max(P[mi_index].second, P[ma_index].first);
    if ((bmax-bmin)*(rmax-rmin) > cand1) {
        cout << cand1 << endl;
        return 0;
    }
    
    multiset<pair<ll, int>> mst;
    mst.insert({bmin, mi_index});
    mst.insert({bmax, ma_index});
    for (int i = 0; i < N; i++) {
        if (i == mi_index || i == ma_index) continue;
        mst.insert({P[i].first, i});
    }
    cand2 = (rmax-rmin)*((*mst.rbegin()).first - (*mst.begin()).first);
    for (int i = 0; i < N; i++) {
        if (i == mi_index || i == ma_index) continue;
        mst.erase(mst.find({P[i].first, i}));
        mst.insert({P[i].second, i});
        cand2 = min(cand2, (rmax-rmin)*((*mst.rbegin()).first - (*mst.begin()).first));
    }
    
    cout << min(cand1, cand2) << endl;
    return 0;
}
