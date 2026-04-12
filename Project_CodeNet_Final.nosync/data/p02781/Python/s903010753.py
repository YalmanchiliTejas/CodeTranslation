import numpy as np

S = input()
N = int(S)
K = int(input())

keta = len(S)

ans = 0
if keta < K:
    print(ans)
    exit()

dp = np.zeros((keta+2,4,2), dtype = int)
dp[0][0][0] = 1
for i in range(keta):
    for j in range(4):
        for k in range(2):
            nd = int(S[i])
            for d in range(10):
                ni = i+1
                nj = j
                nk = k
                if d != 0:
                    nj += 1
                if nj > K:
                    continue
                if k==0:
                    if d > nd: continue
                    if d < nd: nk=1
                dp[ni][nj][nk] += dp[i][j][k]

ans = dp[keta][K][0] + dp[keta][K][1]
print(ans)