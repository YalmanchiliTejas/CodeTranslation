#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

int main() {

    ll N;
    cin >> N;
    vector<string> S(N);
    vector<vector<ll>> A(N, vector<ll>(26));

    rep(i, N) {
        rep(j, 26) {
            A[i][j] = 0;
        }
    }

    rep(i, N) {
        cin >> S[i];
        rep(j, S[i].size()) {
            A[i][S[i][j] - 'a']++;
        }
    }

   string ans = "";
   ll tmp;
   char w;

    rep(j, 26) {
        tmp = 50;
        rep(i, N) {
            tmp = min(tmp, A[i][j]);
        }
        w = 'a' + j;
        rep(i, tmp){
            ans = ans + w;
        }
    }

    cout << ans;
    
    return 0;
}