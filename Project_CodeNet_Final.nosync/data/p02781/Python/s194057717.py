import numpy as np

N = input().strip()
K = int(input().strip())
lenN = len(N)

dp = np.zeros((lenN+1, 2, 4))
dp[0][1][0] = 1
for keta in range(lenN):
    for flag in range(2):
        for k in range(K+1):
            for i in range(10):
                nk = k
                nflag = flag
                if flag:
                    if i > int(N[keta]):
                        continue
                    if i < int(N[keta]):
                        nflag = 0
                if i != 0:
                    nk = k + 1
                if nk > K:
                    continue
                dp[keta+1][nflag][nk]+=dp[keta][flag][k]

print(int(dp[lenN][0][K] + dp[lenN][1][K]))
