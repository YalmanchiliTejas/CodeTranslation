n = str(input())
K = int(input())
dp=[[[0]*2 for j in range(4)] for i in range(len(n)+1)]

dp[0][0][0]=1

for i in range(len(n)):
    for j in range(4):
        for k in range(2):
            ntemp = int(n[i])
            for d in range(10):
                ni = i+1
                nj = j
                nk = k
                if d != 0: nj= nj+1
                if nj > K:continue
                if k == 0:
                    if d > ntemp:continue
                    if d < ntemp:nk = 1
                dp[ni][nj][nk] += dp[i][j][k]
ans = dp[len(n)][K][0] + dp[len(n)][K][1]
print(ans)
