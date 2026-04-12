#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef vector<int> vi;

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
        vi sa0, sa1, ta0, ta1, sb0, sb1, tb0, tb1;
        for (int j = 0; j < n; j++) {
            if (!s[j] && (u[j] >> i & 1)) {
                sa1.push_back(j);
            } else if (!s[j] && !(u[j] >> i & 1)) {
                sb0.push_back(j);
            } else if (s[j] && (u[j] >> i & 1)) {
                sb1.push_back(j);
            } else {
                sa0.push_back(j);
            }

            if (!t[j] && (v[j] >> i & 1)) {
                ta1.push_back(j);
            } else if (!t[j] && !(v[j] >> i & 1)) {
                tb0.push_back(j);
            } else if (t[j] && (v[j] >> i & 1)) {
                tb1.push_back(j);
            } else {
                ta0.push_back(j);
            }
        }

        if (sa0.size() > 0 && ta1.size() > 0 || sa1.size() > 0 && ta0.size() > 0) {
            cout << -1 << endl;
            return 0;
        }

        if ((sa0.size() > 0 ^ ta1.size() > 0) && sa1.size() == 0 && ta0.size() == 0 && tb0.size() > 0) {
            ta0.push_back(tb0[0]);
        } else if ((sa1.size() > 0 ^ ta0.size() > 0) && sa0.size() == 0 && ta1.size() == 0 && tb1.size() > 0) {
            ta1.push_back(tb1[0]);
        } else if ((ta0.size() > 0 ^ sa1.size() > 0) && ta1.size() == 0 && sa0.size() == 0 && sb0.size() > 0) {
            sa0.push_back(sb0[0]);
        } else if ((ta1.size() > 0 ^ sa0.size() > 0) && ta0.size() == 0 && sa1.size() == 0 && sb1.size() > 0) {
            sa1.push_back(sb1[0]);
        }

        if (sa0.size() > 0 && sa1.size() > 0) {
            sa1.insert(sa1.end(), sb1.begin(), sb1.end());
        } else if (ta0.size() > 0 && ta1.size() > 0) {
            ta1.insert(ta1.end(), tb1.begin(), tb1.end());
        } else if (sa0.size() > 0 && ta0.size() > 0) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    a[j][k] ^= 1ull << i;
                }
            }
        } else if (sa1.size() > 0 && ta1.size() > 0) {
            ;
        } else if (sa0.size() > 0) {
            if (sb0.size() <= 1) {
                cout << -1 << endl;
                return 0;
            } else {
                for (int j = 0; j < n; j++) {
                    a[j%2?sb0[0]:sb0[1]][j] ^= 1ull << i;
                }
            }
        } else if (sa1.size() > 0) {
            if (sb1.size() <= 1) {
                cout << -1 << endl;
                return 0;
            } else {
                for (int j = 0; j < n; j++) {
                    a[j%2?sb1[0]:sb1[1]][j] ^= 1ull << i;
                }
                sa1.insert(sa1.end(), sb1.begin() + 2, sb1.end());
            }
        } else if (ta0.size() > 0) {
            if (tb0.size() <= 1) {
                cout << -1 << endl;
                return 0;
            } else {
                for (int j = 0; j < n; j++) {
                    a[j][j%2?tb0[0]:tb0[1]] ^= 1ull << i;
                }
            }
        } else if (ta1.size() > 0) {
            if (tb1.size() <= 1) {
                cout << -1 << endl;
                return 0;
            } else {
                for (int j = 0; j < n; j++) {
                    a[j][j%2?tb1[0]:tb1[1]] ^= 1ull << i;
                }
                ta1.insert(ta1.end(), tb1.begin() + 2, tb1.end());
            }
        } else {
            for (int j = 0; j < n; j++) {
                a[j][j] ^= 1ull << i;
            }
        }

        for (int x : sa0) {
            for (int j = 0; j < n; j++) {
                a[x][j] &= ~(1ull << i);
            }
        }
        for (int x : sa1) {
            for (int j = 0; j < n; j++) {
                a[x][j] |= 1ull << i;
            }
        }
        for (int x : ta0) {
            for (int j = 0; j < n; j++) {
                a[j][x] &= ~(1ull << i);
            }
        }
        for (int x : ta1) {
            for (int j = 0; j < n; j++) {
                a[j][x] |= 1ull << i;
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
