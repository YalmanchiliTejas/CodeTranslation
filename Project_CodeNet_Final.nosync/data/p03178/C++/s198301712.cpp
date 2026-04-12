#include <cstdio>
#include <cstring>

const int MAXK = 100005;
const int MAXD = 105;
const int MOD = 1000000007;

char K[MAXK];
int f[MAXK][MAXD][2], len, d;

int dp(int curr, int sum, int lim) {
    if (curr == len) return sum == 0;
    if (f[curr][sum][lim] != -1) return f[curr][sum][lim];

    int &F = f[curr][sum][lim];
    F = 0;

    if (lim) {
        F += dp(curr + 1, (sum + K[curr] - '0') % d, 1);
        F >= MOD ? F -= MOD : 0;
    }
    for (int i = 0; i < (lim ? K[curr] - '0' : 10); i++) {
        F += dp(curr + 1, (sum + i) % d, 0);
        F >= MOD ? F -= MOD : 0;
    }

    return F;
}

int main() {
    scanf("%s %d", K, &d);
    len = std::strlen(K);
    std::memset(f, -1, sizeof (f));

    int ans = dp(0, 0, 1) - 1;
    ans < 0 ? ans += MOD : 0;
    printf("%d\n", ans);
    
    return 0;
}