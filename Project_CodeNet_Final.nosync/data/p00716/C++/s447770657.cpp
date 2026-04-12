#include <bits/stdc++.h>
using namespace std;

#define rep(i,j) for(int (i)=0;(i)<(j);++(i))

int main() {
    int m;
    cin >> m;
    while (m--) {
        int ini, y, n, ans = -1;
        cin >> ini >> y >> n;
        rep(i, n) {
            int f, com;
            double rate;
            cin >> f >> rate >> com;
            int tini = ini;
            int tnri = 0;
            rep(j, y) {
                int t = tini*rate;
                if (f) tini = tini+t-com;
                else {
                    tini -= com;
                    tnri += t;
                }
            }
            tini += tnri;
            ans = max(tini, ans);
        }
        cout << ans << endl;
    }
}