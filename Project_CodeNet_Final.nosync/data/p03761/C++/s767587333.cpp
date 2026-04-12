#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    string S;
    vector<vector<int>> c(n, vector<int>(26, 0));
    rep(i, n) {
        cin >> S;
        rep(j, S.size()) {
            c[i][(int)(S[j] - 'a')]++;
        }
    }
    rep(i, 26) {
        int cmin = 50;
        rep(j, n) {
            cmin = min(cmin, c[j][i]);
        }
        rep(j, cmin) cout << (char)(i + 'a');
    }
    cout << endl;
}