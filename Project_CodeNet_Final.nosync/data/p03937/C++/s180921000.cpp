#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
        ll H, W; cin >> H >> W;
        vector<vector<ll>> v(H, vector<ll>(W, 0));
        rep(i,H) {
                string s; cin >> s;
                rep(j,W) {
                        if (s[j] == '#') {
                                v[i][j] = 1;
                        }
                }
        }
        ll prev_r = -1;
        ll cur_l = 0;
        rep(i,H) {
                ll r = -1;
                ll l = -1;
                rep(j,W) {
                        if (v[i][j] == 1) {
                                r = j;
                                if (l == -1) {
                                        l = j;
                                }
                        }
                }
                if (prev_r != -1) {
                        if (l != prev_r) {
                                cout << "Impossible" << endl;
                                exit(0);
                        }
                }
                prev_r = r;
        }
        cout << "Possible" << endl;



}
