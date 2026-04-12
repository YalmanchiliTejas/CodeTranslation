#include <cassert>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    unsigned long long a[n][n], u[n], v[n];
    int s[n], t[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> u[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    memset(a, 0, sizeof a);
    for (int e = 0; e < 64; e++) {
        vector<int> r_all[2], r_some[2], c_all[2], c_some[2];
        for (int i = 0; i < n; i++) {
            if (s[i] == 1)
                if ((u[i] >> e) & 1) r_some[1].push_back(i);
                else r_all[0].push_back(i);
            else
                if ((u[i] >> e) & 1) r_all[1].push_back(i);
                else r_some[0].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            if (t[i] == 1)
                if ((v[i] >> e) & 1) c_some[1].push_back(i);
                else c_all[0].push_back(i);
            else
                if ((v[i] >> e) & 1) c_all[1].push_back(i);
                else c_some[0].push_back(i);
        }
        for (int x = 0; x < 2; x++) {
            if ((!r_all[x].empty() && !c_all[x^1].empty()) ||
                (!r_some[x].empty() && c_all[x^1].size() == n) ||
                (r_all[x].size() == n && !c_some[x^1].empty())) {
                cout << "-1\n";
                return 0;
            }
        }

        for (int i : r_all[1]) for (int j = 0; j < n; j++) a[i][j] |= 1LL<<e;
        for (int j : c_all[1]) for (int i = 0; i < n; i++) a[i][j] |= 1LL<<e;
        for (int i : r_some[1]) for (int j : c_some[1]) a[i][j] |= 1LL<<e;
        for (int x = 0; x < 2; x++) {
            if (x == 0 && (!c_some[0].empty() || !c_all[0].empty()))
                for (int i : r_some[0]) for (int j : c_some[1]) a[i][j] |= 1LL<<e;
            else if (x == 1 && (!r_some[0].empty() || !r_all[0].empty()))
                for (int i : r_some[1]) for (int j : c_some[0]) a[i][j] |= 1LL<<e;
            else if (x == 0 && (!r_some[1].empty() || !r_all[1].empty()))
                ;
            else if (x == 1 && (!c_some[1].empty() || !c_all[1].empty()))
                ;
            else if (r_some[x].size() > 1 && c_some[x^1].size() > 1) {
                for (int i = 0; i < r_some[x].size(); i++)
                    for (int j = 0; j < c_some[x^1].size(); j++)
                        if ((i + j) % 2) a[r_some[x][i]][c_some[x^1][j]] |= 1LL<<e;
            } else if (!r_some[x].empty() && !c_some[x^1].empty()) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    // check
    for (int i = 0; i < n; i++) {
        unsigned long long acc = a[i][0];
        if (s[i] == 0) for (int j = 1; j < n; j++) acc &= a[i][j];
        else for (int j = 1; j < n; j++) acc |= a[i][j];
        assert (acc == u[i]);
    }
    for (int j = 0; j < n; j++) {
        unsigned long long acc = a[0][j];
        if (t[j] == 0) for (int i = 1; i < n; i++) acc &= a[i][j];
        else for (int i = 1; i < n; i++) acc |= a[i][j];
        assert (acc == v[j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << a[i][j] << ' ';
        cout << endl;
    }
}
