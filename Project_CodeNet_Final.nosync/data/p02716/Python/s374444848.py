import sys
import numpy as np

sys.setrecursionlimit(10 ** 9)

N = int(input())
A = list(map(int,input().split()))

dp = np.full((N, 3), 0, dtype=int)

dp[0][0] = A[0]
dp[1][1] = A[1]
if N != 2:
    dp[2][2] = A[2]
    dp[2][0] = A[0] + A[2]
for i in range(3,N):
    if i & 1:
        dp[i][1] = max(dp[i-3][0], dp[i-2][1]) + A[i]
    else:
        dp[i][0] = dp[i-2][0] + A[i]
        dp[i][2] = max(dp[i-4][0], dp[i-3][1], dp[i-2][2]) + A[i]

if N & 1:
    ans = max(dp[-3][0], dp[-2][1], dp[-1][2])
else:
    ans = max(dp[-2][0], dp[-1][1])

print(ans)    