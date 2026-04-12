#include <bits/stdc++.h>

using namespace std;

static long long count_patty (int level, long long n_eat) {
    /* level-1 のバーガーの層数とパティの枚数 */
    long long n_layer = (1LL << (level+1)) - 3;
    long long n_patty = (1LL << level) - 1;

    if ( level == 0 )
        return 1;

    if ( n_eat <= 1 )
        return 0;
    else if ( n_eat <= n_layer + 1 )
        return count_patty(level-1, n_eat-1);
    else if ( n_eat == n_layer + 2 )
        return 1 + n_patty;
    else if ( n_eat <= n_layer * 2 + 2 ) {
        return 1 + n_patty + count_patty(level-1, n_eat-n_layer-2);
    }
    return 1 + 2 * n_patty;
}

int main (void) {
    long long N, X;
    cin >> N >> X;

    long long ans = count_patty(N, X);
    cout << ans << endl;
    return 0;
}
