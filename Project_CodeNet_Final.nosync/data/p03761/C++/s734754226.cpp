#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__

int main() {
    int N;
    cin >> N;

    vector<vector<int>> scnt(N);
    rep(i, N) {
        string S;
        cin >> S;

        vi sv(26, 0);

        rep(j, S.size()) {
            int x = S.at(j) - 'a';
            sv[x]++;
        }
        scnt[i] = sv;
    }

    string res;
    rep(i, 26) {
        int cmin = INF;
        rep(j, N) {
            cmin = min(cmin, scnt[j][i]);
        }

        rep(j, cmin) {
            res += (i + 'a');
        }
    }

    cout << res << endl;
}