#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, s, t) for(int i = (s); i < (t); i++)

int N;
ll A[3005], DP[3005][3005];

ll sol = 0;

// 0 - Taro's turn
// 1 - Jiro's turn

ll rek(int l, int r, int turn) {
    if(l>r) return 0;
    if(l==r) {
        return DP[l][r] = A[l]*(1-turn);
    }
    if(DP[l][r] != 0) return DP[l][r];
    ll sol1 = rek(l+1, r, 1-turn) + A[l];
    ll sol2 = rek(l, r-1, 1-turn) + A[r];
    if(turn == 0) {
        DP[l][r] = max(sol1, sol2);
    }
    else {
        DP[l][r] = min(sol1 - A[l], sol2 - A[r]);
    }
    return DP[l][r];
}

int main()
{
    scanf("%d", &N);
    ll sum = 0;
    REP(i, 0, N) {
        scanf("%lld", &A[i]);
        sum += A[i];
    }

    ll x = rek(0, N-1, 0);
    printf("%lld\n", x-(sum-x));

    return 0;
}
