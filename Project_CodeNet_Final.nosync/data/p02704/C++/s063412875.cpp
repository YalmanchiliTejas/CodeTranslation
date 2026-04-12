#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

const int LGA = 64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int s[n], t[n];
    ull u[n], v[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> u[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (n == 1) {
        if (u[0] == v[0]) {
            cout << u[0] << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    ull a[n][n];
    fill(a[0], a[n], 0);

    for (int i = 0; i < LGA; i++) {
        bool sa0[n], sa1[n], ta0[n], ta1[n];
        bool sb0[n], sb1[n], tb0[n], tb1[n];
        fill(sa0, sa0+n, false);
        fill(sa1, sa1+n, false);
        fill(ta0, ta0+n, false);
        fill(ta1, ta1+n, false);
        fill(sb0, sb0+n, false);
        fill(sb1, sb1+n, false);
        fill(tb0, tb0+n, false);
        fill(tb1, tb1+n, false);
        int sa0c = 0, sa1c = 0, ta0c = 0, ta1c = 0;
        int sb0c = 0, sb1c = 0, tb0c = 0, tb1c = 0;
        for (int j = 0; j < n; j++) {
            if (!s[j] && (u[j] >> i & 1)) {
                sa1[j] = true;
                sa1c++;
            } else if (!s[j] && !(u[j] >> i & 1)) {
                sb0[j] = true;
                sb0c++;
            } else if (s[j] && (u[j] >> i & 1)) {
                sb1[j] = true;
                sb1c++;
            } else {
                sa0[j] = true;
                sa0c++;
            }

            if (!t[j] && (v[j] >> i & 1)) {
                ta1[j] = true;
                ta1c++;
            } else if (!t[j] && !(v[j] >> i & 1)) {
                tb0[j] = true;
                tb0c++;
            } else if (t[j] && (v[j] >> i & 1)) {
                tb1[j] = true;
                tb1c++;
            } else {
                ta0[j] = true;
                ta0c++;
            }
        }

        if (sa0c && ta1c || sa1c && ta0c) {
            cout << -1 << endl;
            return 0;
        }

        if ((sa0c ^ ta1c) && !sa1c && !ta0c && tb0c) {
            int t;
            for (int j = 0; j < n; j++) {
                if (tb0[j]) {
                    t = j;
                }
            }
            tb0[t] = false;
            tb0c--;
            ta0[t] = true;
            ta0c++;
        } else if ((sa1c ^ ta0c) && !sa0c && !ta1c && tb1c) {
            int t;
            for (int j = 0; j < n; j++) {
                if (tb1[j]) {
                    t = j;
                }
            }
            tb1[t] = false;
            tb1c--;
            ta1[t] = true;
            ta1c++;
        } else if ((ta0c ^ sa1c) && !ta1c && !sa0c && sb0c) {
            int t;
            for (int j = 0; j < n; j++) {
                if (sb0[j]) {
                    t = j;
                }
            }
            sb0[t] = false;
            sb0c--;
            sa0[t] = true;
            sa0c++;
        } else if ((ta1c ^ sa0c) && !ta0c && !sa1c && sb1c) {
            int t;
            for (int j = 0; j < n; j++) {
                if (sb1[j]) {
                    t = j;
                }
            }
            sb1[t] = false;
            sb1c--;
            sa1[t] = true;
            sa1c++;
        }

        if (sa0c && sa1c) {
            for (int j = 0; j < n; j++) {
                if (sb1[j]) {
                    sb1[j] = false;
                    sb1c--;
                    sa1[j] = true;
                    sa1c++;
                }
            }
        } else if (ta0c && ta1c) {
            for (int j = 0; j < n; j++) {
                if (tb1[j]) {
                    tb1[j] = false;
                    tb1c--;
                    ta1[j] = true;
                    ta1c++;
                }
            }
        } else if (sa0c && ta0c) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    a[j][k] ^= 1ull << i;
                }
            }
        } else if (sa1c && ta1c) {
            ;
        } else if (sa0c) {
            if (sb0c <= 1) {
                cout << -1 << endl;
                return 0;
            } else {
                int t1 = -1, t2 = -1;
                for (int j = 0; j < n; j++) {
                    if (sb0[j]) {
                        if (t1 == -1) {
                            t1 = j;
                        } else if (t2 == -1) {
                            t2 = j;
                        } else {
                            sb0[j] = false;
                            sb0c--;
                            sa0[j] = true;
                            sa0c++;
                        }
                    }
                }
                for (int j = 0; j < n; j++) {
                    a[j%2?t1:t2][j] ^= 1ull << i;
                }
            }
        } else if (sa1c) {
            if (sb1c <= 1) {
                cout << -1 << endl;
                return 0;
            } else {
                int t1 = -1, t2 = -1;
                for (int j = 0; j < n; j++) {
                    if (sb1[j]) {
                        if (t1 == -1) {
                            t1 = j;
                        } else if (t2 == -1) {
                            t2 = j;
                        } else {
                            sb1[j] = false;
                            sb1c--;
                            sa1[j] = true;
                            sa1c++;
                        }
                    }
                }
                for (int j = 0; j < n; j++) {
                    a[j%2?t1:t2][j] ^= 1ull << i;
                }
            }
        } else if (ta0c) {
            if (tb0c <= 1) {
                cout << -1 << endl;
                return 0;
            } else {
                int t1 = -1, t2 = -1;
                for (int j = 0; j < n; j++) {
                    if (tb0[j]) {
                        if (t1 == -1) {
                            t1 = j;
                        } else if (t2 == -1) {
                            t2 = j;
                        } else {
                            tb0[j] = false;
                            tb0c--;
                            ta0[j] = true;
                            ta0c++;
                        }
                    }
                }
                for (int j = 0; j < n; j++) {
                    a[j][j%2?t1:t2] ^= 1ull << i;
                }
            }
        } else if (ta1c) {
            if (tb1c <= 1) {
                cout << -1 << endl;
                return 0;
            } else {
                int t1 = -1, t2 = -1;
                for (int j = 0; j < n; j++) {
                    if (tb1[j]) {
                        if (t1 == -1) {
                            t1 = j;
                        } else if (t2 == -1) {
                            t2 = j;
                        } else {
                            tb1[j] = false;
                            tb1c--;
                            ta1[j] = true;
                            ta1c++;
                        }
                    }
                }
                for (int j = 0; j < n; j++) {
                    a[j][j%2?t1:t2] ^= 1ull << i;
                }
            }
        } else {
            for (int j = 0; j < n; j++) {
                a[j][j] ^= 1ull << i;
            }
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (sa0[j] || ta0[k]) {
                    a[j][k] &= ~(1ull << i);
                }
                if (sa1[j] || ta1[k]) {
                    a[j][k] |= 1ull << i;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " \n"[j==n-1];
        }
    }
    cout.flush();

    return 0;
}
