from itertools import accumulate
N, *A = map(int, open(0).read().split())

INF = 1 << 60
dp = [[-INF]*2 for _ in [0]*N]
dp[0][0] = 0

if N & 1:
    for i, a in enumerate(A):
        for j in range(i//2+1, i//2-1, -1):
            dp[j][0] = max(dp[j][0], dp[j][1])
            if j > 0:
                dp[j][1] = dp[j-1][0] + a
else:
    for i, a in enumerate(A):
        for j in range(i//2+1, (i+1)//2-1, -1):
            dp[j][0] = max(dp[j][0], dp[j][1])
            dp[j][1] = dp[j-1][0] + a

print(max(dp[N//2]))
