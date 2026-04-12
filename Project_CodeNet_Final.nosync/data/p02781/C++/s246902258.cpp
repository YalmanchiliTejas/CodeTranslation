#include <stdio.h>
#include <string.h>

typedef long long int ll;
int numSize, K;
ll memo[110][2][110];
char num[110];

ll dp(int pos, int small, ll noZeros) {
    if (pos == numSize) {
        if (noZeros == K) 
            return 1;
        else 
            return 0;
    }
    if (memo[pos][small][noZeros] != -1) return memo[pos][small][noZeros];
    ll ans = 0;
    int d, limit = (small ? 9 : num[pos] - 48);
    for (d = 0; d <= limit; d++) {
        if (d < limit)
            ans += dp(pos + 1, 1, noZeros + (d ? 1 : 0));
        else
            ans += dp(pos + 1, small, noZeros + (d ? 1 : 0));
    }
    return memo[pos][small][noZeros] = ans;
}

int main() {

    scanf("%s %d", num, &K);
    numSize = strlen(num);
    memset(memo, -1, sizeof(memo));
    printf("%lld\n", dp(0, 0, 0));   
    return 0;
}