# でつoO(YOU PLAY WITH THE CARDS YOU'RE DEALT..)
from itertools import product
import sys
INF = 10**16
def main(N, A):
    dp = [[[-INF] * 2 for __ in range(3)] for _ in range(N + 1)]
    dp[0][1][0] = dp[0][2][0] = 0
    for i in range(1, N + 1):
        pi = ((i - 1) // 2 - 1, (i - 1) // 2, i // 2)
        ni = (i // 2 - 1, i // 2, (i + 1) // 2)
        for pii, nii, pk, nk in product(range(3), range(3), range(2), range(2)):
            pj, nj = pi[pii], ni[nii]
            if pj > nj or pj + 2 <= nj: continue
            if pj == nj and nk == 1: continue
            if pj < nj and nk == 0: continue
            if pk == 1 and nk == 1: continue
            if dp[i - 1][pii][pk] == -INF: continue
            dp[i][nii][nk] = max(dp[i][nii][nk], dp[i - 1][pii][pk] + (A[i - 1] if nk == 1 else 0))
    ans = -INF
    for k in range(2):
        ans = max(ans, dp[N][1][k])
    print(ans)

if __name__ == '__main__':
    input = sys.stdin.readline
    N = int(input())
    *A, = map(int, input().split())
    main(N, A)
