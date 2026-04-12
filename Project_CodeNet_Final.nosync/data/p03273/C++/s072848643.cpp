#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int H, W; cin >> H >> W;
    vector<string> A(H);
    REP(i, 0, H) cin >> A[i];

    vector<bool> whiter(H), whitec(W);
    REP(i, 0, H) {
        bool white = true;
        REP(j, 0, W) {
            if (A[i][j] == '#') white = false;
        }
        whiter[i] = white;
    }
    REP(j, 0, W) {
        bool white = true;
        REP(i, 0, H) {
            if (A[i][j] == '#') white = false;
        }
        whitec[j] = white;
    }

    REP(i, 0, H) {
        if (whiter[i]) continue;
        REP(j, 0, W) {
            if (whitec[j]) continue;
            cout << A[i][j];
        }
        cout << endl;
    }
    return 0;
}