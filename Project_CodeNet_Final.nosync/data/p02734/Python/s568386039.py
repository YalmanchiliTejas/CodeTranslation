import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

n, S = na()
a = na()
mod = 998244353

def go(f, t, step, a, S):
    dp = [0] * (S+1)
    dp[0] = 1
    ret = [0] * (S+1)
    while f != t:
        for i in range(S, a[f]-1, -1):
            dp[i] += dp[i-a[f]]
            if dp[i] >= mod:
                dp[i] -= mod
        for i in range(S+1):
            ret[i] += dp[i]
        f += step
    for i in range(S+1):
        ret[i] %= mod
    return ret

def dfs(l, r, a, S):
    if r-l <= 1:
        return 1 if a[l] == S else 0
    h = (l+r)//2
    L = go(h-1, l-1, -1, a, S)
    R = go(h, r, 1, a, S)
    # print(l, r, L, R)
    return sum(L[i] * R[S-i] for i in range(S+1)) + dfs(l, h, a, S) + dfs(h, r, a, S)

print(dfs(0, n, a, S) % mod)
