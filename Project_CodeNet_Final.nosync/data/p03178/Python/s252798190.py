K = input()
D = int(input())
N = len(K)
mod = 10 ** 9 + 7

dp = [[[0]*2 for _ in range(D)] for _ in range(10000 + 5)]
dp[0][0][0] = 1

for i in range(N):
    nd = int(K[i])
    for j in range(D):
        for k in range(2):
            for d in range(10):
                ni = i + 1
                nj = (j+d) % D
                nk = k
                if nk == 0:
                    if d > nd:
                        continue
                    if d < nd:
                        nk += 1
                dp[ni][nj][nk] += dp[i][j][k]
                dp[ni][nj][nk] %= mod

ans = (dp[N][0][0] + dp[N][0][1] - 1 + mod) % mod
print(ans)
