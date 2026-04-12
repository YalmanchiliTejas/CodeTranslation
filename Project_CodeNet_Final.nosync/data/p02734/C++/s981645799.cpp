#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353, nax = 3005;


void plusle (int &a, int b) {
    if ((a += b) >= mod) a -= mod;
}

int dp[nax], f[nax];
int n, s;

int main () {
    scanf("%d %d", &n, &s);
    f[0] = 1;
    int ans = 0;

    for (int i = 1 ; i <= n; ++ i) {
        int x;
        scanf("%d", &x);
        for (int j = s ; j >= x ; -- j) {
            plusle(f[j], f[j - x]);
        }
        ++ f[0];

        plusle(ans, f[s]);
    }

    printf("%d\n", ans);
}

