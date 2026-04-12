# Author: cr4zjh0bp
# Created: Mon Mar  2 04:27:45 UTC 2020
import sys
 
stdin = sys.stdin
inf = 1 << 60
mod = 1000000007
 
ni = lambda: int(ns())
nin = lambda y: [ni() for _ in range(y)]
na = lambda: list(map(int, stdin.readline().split()))
nan = lambda y: [na() for _ in range(y)]
ns = lambda: stdin.readline().rstrip()
nsn = lambda y: [ns() for _ in range(y)]
ncl = lambda y: [list(ns()) for _ in range(y)]
nas = lambda: stdin.readline().split()

s = ns()
N = len(s)
K = ni()
dp = [[[0] * 4 for _ in range(2)] for _ in range(N + 1)]
dp[0][0][0] = 1

for i in range(N):
    for j in range(2):
        D = int(s[i])
        n = 9 if j == 1 else D
        for d in range(n + 1):
            for k in range(4):
                ni, nj, nk = i + 1, j, k
                if d != 0:
                    nk += 1
                if nk > K:
                    continue
                if d < D:
                    nj = 1
                dp[ni][nj][nk] += dp[i][j][k]

print(dp[N][0][K] + dp[N][1][K])