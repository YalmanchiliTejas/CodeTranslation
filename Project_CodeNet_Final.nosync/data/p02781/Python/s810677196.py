s = input()
n = int(s)
keta = len(s)
k = int(input())
# k=1,2,3
ans = 0

dp = [[[0] * (2) for _ in range(k + 1)] for _ in range(keta + 1)]
dp[0][0][0] = 1
for i in range(keta):
    d = int(s[i])
    for j in range(k + 1):
        for smaller in range(2):

            for t in range(10):
                ni = i + 1
                nj = j
                nsmaller = smaller
                if t > 0:
                    nj = j + 1
                if nj > k:
                    continue
                if nsmaller == 0:
                    if t > d:
                        continue
                    if t < d:
                        nsmaller = 1
                dp[ni][nj][nsmaller] += dp[i][j][smaller]
print(dp[keta][k][1] + dp[keta][k][0])
