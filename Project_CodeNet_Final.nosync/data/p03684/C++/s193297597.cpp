#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif


    int n;
    while (cin >> n) {
        vector<pair<int, int> > a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> get = [&](int x) {
            if (x == p[x]) return x;
            return p[x] = get(p[x]);
        };
        auto uni = [&](int u, int v) {
            u = get(u);
            v = get(v);
            if (u == v) return 0;
            p[v] = u;
            return 1;
        };

        map<int, vector<int> > mpx, mpy;
        for (int i = 0; i < n; i++) {
            mpx[a[i].first].push_back(i);
            mpy[a[i].second].push_back(i);
        }
        vector<int> vctx, vcty;
        for (auto it : mpx) {
            vctx.push_back(it.first);
            for (int i = 1; i < (int)it.second.size(); i++) uni(it.second[0], it.second[i]);
        }
        for (auto it : mpy) {
            vcty.push_back(it.first);
            for (int i = 1; i < (int)it.second.size(); i++) uni(it.second[0], it.second[i]);
        }

        vector<pair<int, pair<int, int> > > vct;
        for (int i = 1; i < (int)vctx.size(); i++) {
            vct.push_back({vctx[i] - vctx[i - 1], make_pair(mpx[vctx[i - 1]][0], mpx[vctx[i]][0])});
        }
        for (int i = 1; i < (int)vcty.size(); i++) {
            vct.push_back({vcty[i] - vcty[i - 1], make_pair(mpy[vcty[i - 1]][0], mpy[vcty[i]][0])});
        }
        sort(vct.begin(), vct.end());
        int ans = 0;
        for (auto o : vct) {
            if (uni(o.second.first, o.second.second)) {
                ans += o.first;
            }
        }
        cout << ans << endl;
    }


#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}