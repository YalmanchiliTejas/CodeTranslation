#include <bits/stdc++.h>
using namespace std;
 
#define ll unsigned long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 505;
ll a[N][N], s[N], t[N], u[N], v[N], u1[N], v1[N];
int n;
bool used_r[N], used_c[N];

void solve(int b) {
    bool sol_row[2] = {false, false},
        sol_col[2] = {false, false};

    fill(used_r, used_r + n, 0);
    fill(used_c, used_c + n, 0);

    for (int i = 0; i < n; i++) {
        u1[i] = (u[i] >> b) & 1;
        v1[i] = (v[i] >> b) & 1;

        if ((s[i] ^ u1[i])) {
            used_r[i] = true;
            sol_row[u1[i]] = true;

            for (int j = 0; j < n; j++) {
                a[i][j] |= (u1[i] << b);
            }
        }

        if ((t[i] ^ v1[i])) {
            used_c[i] = true;
            sol_col[v1[i]] = true;

            for (int j = 0; j < n; j++) {
                a[j][i] |= (v1[i] << b);
            }
        }
    }

    if (sol_row[0] && sol_col[1] ||
        sol_row[1] && sol_col[0])
        return;

    if (sol_row[1] && sol_col[1] ||
        sol_row[0] && sol_col[0]) {

        ll x = (sol_row[1] ? 1 : 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!used_r[i] && !used_c[j])
                    a[i][j] |= ((x ^ (ll)1) << b);
            }
        }
    }
    else if (sol_row[0] || sol_row[1]) {
        int non_sol = 0, last = 0;
        for (int i = 0; i < n; i++) {
            if (!used_r[i]) {
                non_sol++;
                last = i;
            }
        }

        if (non_sol > 1) {
            for (int i = 0, k = 0; i < n; i++) {
                if (!used_r[i]) {
                    for (int j = 0; j < n; j++) {
                        if ((j + k) & 1)
                            a[i][j] |= ((ll)1 << b);
                    }
                    k++;
                }
            }
        }
        else if (non_sol == 1) {
            for (int i = 0; i < n; i++) {
                if ((v1[i] ^ t[i]) == 0 && !sol_row[v1[i]]) {
                    a[last][i] |= (v1[i] << b);
                }
                else {
                    a[last][i] |= (u1[last] << b);
                }
            }
        }
    }
    else if (sol_col[0] || sol_col[1]) {
        int non_sol = 0, last = 0;
        for (int i = 0; i < n; i++) {
            if (!used_c[i]) {
                non_sol++;
                last = i;
            }
        }

        if (non_sol > 1) {
            for (int i = 0, k = 0; i < n; i++) {
                if (!used_c[i]) {
                    for (int j = 0; j < n; j++) {
                        if ((j + k) & 1)
                            a[j][i] |= ((ll)1 << b);
                    }
                    k++;
                }
            }
        }
        else if (non_sol == 1) {
            for (int i = 0; i < n; i++) {
                if ((u1[i] ^ s[i]) == 0 && !sol_col[u1[i]]) {
                    a[i][last] |= (u1[i] << b);
                }
                else {
                    a[i][last] |= (v1[last] << b);
                }
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] |= ((ll)((i + j) & 1) << b);
            }
        }
    }
}

bool check() {
    for (int i = 0; i < n; i++) {
        ll y = 0, x = a[i][0];
        for (int j = 0; j < n; j++) {
            y |= a[i][j];
            x &= a[i][j];
        }
        if (s[i] == 0 && x != u[i] ||
            s[i] == 1 && y != u[i])
            return false;
    }

    for (int i = 0; i < n; i++) {
        ll y = 0, x = a[0][i];
        for (int j = 0; j < n; j++) {
            y |= a[j][i];
            x &= a[j][i];
        }
        if (t[i] == 0 && x != v[i] ||
            t[i] == 1 && y != v[i])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

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
        for (int i = 0; i < 2; i++) {
            a[0][0] = (i == 0 ? v[0] : u[0]);
            if (check()) {
                cout << a[0][0] << "\n";
                return 0;
            }
        }
        cout << "-1";
    }
    else {

        for (int i = 0; i < 64; i++) {
            solve(i);
        }
        
        if (check()) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << a[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
        else {
            cout << "-1";
        }

    }

    return 0;
}