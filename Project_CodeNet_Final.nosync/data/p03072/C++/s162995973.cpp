
#include <bits/stdc++.h>

#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using namespace std;

typedef long long LL;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N; cin >> N;
    vector<int> H(N);
    REP(i, N) cin >> H[i];

    int ret = 0;
    int h = 0;
    REP(i, N) {
        if (h <= H[i]) {
            ++ret;
            h = H[i];
        }
    }

    cout << ret << endl;

}
