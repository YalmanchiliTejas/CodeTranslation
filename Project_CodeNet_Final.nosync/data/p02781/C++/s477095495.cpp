#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 102, K = 4;
ll dp[N][K][2];
char s[N];
int k, n;

ll rec(int x, int cnt, int f) {
    if (x == n) {
        return cnt == k;
    }
    if (cnt > k) return 0;
    ll &ret = dp[x][cnt][f];
    if (ret != -1) return ret;
    ret = 0;
    if (f) {
        for (int i = 0; i < s[x] - '0'; i++) {
            ret += rec(x + 1, cnt + (i != 0), 0);
        }
        ret += rec(x + 1, cnt + (s[x] != '0'), 1);
    } else {
        for (int i = 0; i < 10; i++) {
            ret += rec(x + 1, cnt + (i != 0), 0);
        }
    }
    return ret;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%s\n%d", s, &k);
    n = strlen(s);
    memset(dp, -1, sizeof dp);
    printf("%lld", rec(0, 0, 1));
    return 0;
}
