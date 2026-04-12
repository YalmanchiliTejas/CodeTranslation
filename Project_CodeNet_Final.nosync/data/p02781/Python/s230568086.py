import sys

stdin = sys.stdin
inf = 1 << 60
mod = 1000000007

sys.setrecursionlimit(10 ** 7)

ni      = lambda: int(ns())
nin     = lambda y: [ni() for _ in range(y)]
na      = lambda: list(map(int, stdin.readline().split()))
nan     = lambda y: [na() for _ in range(y)]
nf      = lambda: float(ns())
nfn     = lambda y: [nf() for _ in range(y)]
nfa     = lambda: list(map(float, stdin.readline().split()))
nfan    = lambda y: [nfa() for _ in range(y)]
ns      = lambda: stdin.readline().rstrip()
nsn     = lambda y: [ns() for _ in range(y)]
ncl     = lambda y: [list(ns()) for _ in range(y)]
nas     = lambda: stdin.readline().split()

n = ni()
s = str(n)
K = ni()

dp = [[[0] * 2 for _ in range(K + 2)] for _ in range(len(s) + 1)]
dp[0][0][0] = 1
for i in range(len(s)):
    for j in range(K + 1):
        for k in range(2):
            dmax = 9 if k else int(s[i])
            for d in range(dmax + 1):
                ni = i + 1
                nj = j + (d != 0)
                nk = k | (d < dmax)
                dp[ni][nj][nk] += dp[i][j][k]

print(dp[len(s)][K][0] + dp[len(s)][K][1])