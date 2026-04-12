#include <bits/stdc++.h>

#define GET_BIT(n, i) (((n) & (1 << ((i)-1))) >> ((i)-1)) // i start from 1
#define SET_BIT(n, i) ((n) | (1 << ((i)-1)))
#define CLR_BIT(n, i) ((n) & ~(1 << ((i)-1)))
#define SHOW_A(x) {cout << #x << " = " << x << endl;}
#define SHOW_B(x, y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define SHOW_C(x, y, z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}
#define REACH_HERE {cout << "REACH_HERE! line: " << __LINE__ << endl;}

const double E = 1e-8;
const double PI = acos(-1);

using namespace std;

const int MAX_N = 100005, MAX_M = 10005;
const int MOD_BASE = 1000000007;

int baba[MAX_N];

int power_modulo(int n, int p, int M) {
    int result = 1;
    while (p > 0) {
        if (p % 2 == 1)
            result = ((long long)result*n) % M;
        p /= 2;
        n = ((long long)n*n) % M;
    }
    return result;
}

int find_baba(int i) {
    if (baba[i] != i) {
        int new_baba = find_baba(baba[i]);
        baba[i] = new_baba;
        return new_baba;
    }
    return i;
}

void solve(int n, int m) {
    for (int i = 1; i <= n; i++) {
        baba[i] = i;
    }
    bool unstable = false;
    int total = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        baba[find_baba(b)] = find_baba(a);
        unstable = true;
    }
    int group = 0;
    for (int i = 1; i <= n; i++) {
        if (find_baba(i) == i) {
            group ++;
        }
    }
    int ans = unstable ? 1 : 0;
    ans += power_modulo(2, group, MOD_BASE);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        solve(n, m);
    }

    return 0;
}