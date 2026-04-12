import sys
sys.setrecursionlimit(2147483647)
INF = 1 << 60
MOD = 998244353
input = lambda:sys.stdin.readline().rstrip()
def resolve():
    n, s = map(int, input().split())
    dp = [0] * (s + 1)
    res = 0
    for a in map(int, input().split()):
        dp[0] += 1
        for i in range(s - a, -1, -1):
            dp[i + a] += dp[i]
            if dp[i + a] >= MOD:
                dp[i + a] -= MOD
        res += dp[s]
        if res >= MOD:
            res -= MOD

    print(res)
resolve()