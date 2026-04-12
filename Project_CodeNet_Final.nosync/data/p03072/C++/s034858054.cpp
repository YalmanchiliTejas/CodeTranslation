#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n;
    cin >> n;
    vector<int>h(n);
    bool ans = true;
    int cnt = 1;
    rep(i, n)cin >> h[i];
    for (int i = 1; i < n; i++) {
        ans = true;
        for (int j = i - 1; j >= 0; j--) {
            if (h[j] > h[i])ans = false;
        }
        if (ans)cnt++;
    }
    cout << cnt << endl;
    return 0;
}
