#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define FPEN freopen("in.txt", "r", stdin);
#define debug(...) \
    { cerr << "# " << __VA_ARGS__ << "\n"; }
#else
#define debug(...)
#define FPEN
#endif
const int maxn = 200009;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef pair<int, int> pi;
const i64 MOD = 119 << 23 | 1;
class {
   public:
    void solve() {
        string s;
        int k;
        cin >> s >> k;
        i64 ans = 0;
        int cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            int num = s[i] - '0';
            for (int j = 0; j < num; ++j) {
                if (j == 0)
                    ans += cal(s.size() - i - 1, k);
                else
                    ans += cal(s.size() - i - 1, k - 1);
            }
            if (num != 0)
                --k;
        }
        if (k == 0)
            ans++;
        cout << ans << '\n';
    }
    i64 d[4] = {1, 9, 9 * 9, 9 * 9 * 9};
    i64 cal(int len, int k) {
        if (k < 0)
            return 0;
        if (k > len)
            return 0;
        if (len == k)
            return d[k];
        i64 res = 1;
        for (int i = 0; i < k; ++i) res = res * (len - i);
        for (int i = 1; i <= k; ++i) res /= i;
        return res * d[k];
    }
} NSPACE;
int main() {
    FPEN;
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    NSPACE.solve();
}