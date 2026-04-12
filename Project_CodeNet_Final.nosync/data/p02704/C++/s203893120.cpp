#include <bits/stdc++.h>
#define int unsigned long long
#define i8 int8_t
#define i32 int32_t

using namespace std;

const i32 maxn = (1 << 18);

i8 a[64][501][501];
int u[501], v[501];

void bad() {
    cout << -1;
    exit(0);
}

signed main() {
    short n;
    cin >> n;
    vector<char> ps(n), pt(n);
    for (i32 i = 0; i < n; i++)
        cin >> ps[i];
    for (i32 i = 0; i < n; i++)
        cin >> pt[i];
    for (i32 i = 0; i < n; i++)
        cin >> u[i];
    for (i32 i = 0; i < n; i++)
        cin >> v[i];
    for (i32 k = 0; k < 64; k++) {
        vector<bool> cu(n), cv(n);
        vector<char> s = ps, t = pt;
        for (i32 i = 0; i < n; i++) {
            cu[i] = (u[i] >> k) % 2;
            cv[i] = (v[i] >> k) % 2;
        }
        for (i32 i = 0; i < n; i++)
            for (i32 j = 0; j < n; j++)
                a[k][i][j] = -1;
        for (i32 i = 0; i < n; i++) {
            if (s[i] - '0' != cu[i]) {
                for (int j = 0; j < n; j++)
                    if (a[k][i][j] == i8(cu[i] ^ 1)) bad();
                    else a[k][i][j] = cu[i];
                s[i] = '#';
            }
        }
        for (i32 i = 0; i < n; i++) {
            if (t[i] - '0' != cv[i]) {
                for (int j = 0; j < n; j++)
                    if (a[k][j][i] == i8(cv[i] ^ 1)) bad();
                    else a[k][j][i] = cv[i];
                t[i] = '#';
            }
        }
        for (i32 i = 0; i < n; i++) {
            if (s[i] == '#') continue;
            for (i32 j = 0; j < n; j++) {
                if ((i8)cu[i] == a[k][i][j]) {
                    s[i] = '#'; break;
                }
                if (a[k][i][j] == -1 &&
                    (t[j] == '#' || cv[j] == cu[i])) {
                    t[j] = s[i] = '#';
                    a[k][i][j] = cu[i];
                    break;
                }
            }
        }
        for (i32 i = 0; i < n; i++) {
            if (t[i] == '#') continue;
            for (i32 j = 0; j < n; j++) {
                if ((i8)cv[i] == a[k][j][i]) {
                    t[i] = '#'; break;
                }
                if (a[k][j][i] == -1 &&
                    (s[j] == '#' || cu[j] == cv[i])) {
                    s[j] = t[i] = '#';
                    a[k][j][i] = cv[i];
                    break;
                }
            }
        }
        vector<i32> cnt(n);
        for (i32 i = 0; i < n; i++) {
            for (i32 j = 0; j < n; j++)
                cnt[i] += (a[k][i][j] == -1);
        }
        for (i32 i = 0; i < n; i++) {
            if (t[i] == '#') continue;
            i32 cj = -1;
            for (i32 j = 0; j < n; j++) {
                if (a[k][j][i] != -1) continue;
                if (cj == -1 || cnt[j] > cnt[cj])
                    cj = j;
            }
            if (cnt[cj] == 0) bad();
            --cnt[cj]; a[k][cj][i] = cv[i];
        }
        for (i32 i = 0; i < n; i++) {
            if (s[i] == '#') continue;
            i32 cj = -1;
            for (i32 j = 0; j < n; j++)
                if (a[k][i][j] == -1 || a[k][i][j] == cu[i]) {
                    cj = j; break;
                }
            if (cj == -1) bad();
            a[k][i][cj] = cu[i];
        }
        for (i32 i = 0; i < n; i++)
            for (i32 j = 0; j < n; j++)
                if (a[k][i][j] == -1) a[k][i][j] = 0;
    }
    for (i32 i = 0; i < n; i++) {
        for (i32 j = 0; j < n; j++) {
            int x = 0;
            for (i32 k = 0; k < 64; k++)
                x += (1ll << k) * a[k][i][j];
            cout << x << ' ';
        }
        cout << '\n';
    }
  	return 0;
}
