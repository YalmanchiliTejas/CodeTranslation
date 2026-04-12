#include<bits/stdc++.h>

using namespace std;

using LL = long long;
const LL infLL = (LL)1e18 + 123;
const int N = (int)1e5 + 5, SEEHT = (int)sqrt(N);

int n, s[N];
LL prefSum[SEEHT][N], suffSum[SEEHT][N], ans;

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) scanf(" %d", s + i);

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < SEEHT; ++j) if (i % j == 0) {
            prefSum[j][i] = s[i] + (i >= j ? prefSum[j][i - j] : 0);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 1; j < SEEHT; ++j) if (i % j == (n - 1) % j) {
            suffSum[j][i] = s[i] + (i + j <= n - 1 ? suffSum[j][i + j] : 0);
        }
    }

    for (int j = 1; j < SEEHT; ++j) {
        for (int i = 1; i * j < n; ++i) {
            int lstSuff = i * j + (n - 1) % j,
                lstPref = (n - 1) - i * j - (n - 1) % j;
            if ( (n - 1) % j == 0 && lstPref >= lstSuff) continue ;
            LL ret = prefSum[j][lstPref] + suffSum[j][lstSuff];
            ans = max(ans, ret);
        }
    }

    for (int j = SEEHT; j < n; ++j) {
        vector<int> pref, suff;
        for (int i = 0; i < n; i += j) pref.push_back(s[i] + (pref.size() ? pref.back() : 0) );
        for (int i = n - 1; i >= 0; i -= j) suff.push_back(s[i] + (suff.size() ? suff.back() : 0) );
        for (int i = 1; i * j < n; ++i) {
            int lstSuff = i * j + (n - 1) % j,
                lstPref = (n - 1) - i * j - (n - 1) % j;
            if ( (n - 1) % j == 0 && lstPref >= lstSuff) continue ;
            LL ret = suff[(int)suff.size() - i - 1] + pref[(int)pref.size() - i - 1];
            ans = max(ans, ret);
        }
    }

    printf("%lld", ans);

    return 0;
}
