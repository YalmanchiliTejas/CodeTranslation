import sys

stdin = sys.stdin
inf = 1 << 60
mod = 1000000007

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

k = ni()
s = str(k)
n = len(s)
d = ni()

dp = [[[0] * 2 for _ in range(d + 1)] for _ in range(n + 1)]
dp[0][0][0] = 1
for i in range(n):
    for j in range(d):
        for k in range(2):
            dmax = 9 if k else int(s[i])
            for D in range(dmax + 1):
                ni = i + 1
                nj = (j + D) % d
                nk = k | (D < dmax)
                dp[ni][nj][nk] += dp[i][j][k]
                dp[ni][nj][nk] %= mod

ans = dp[n][0][0] + dp[n][0][1] - 1
print(ans % mod)