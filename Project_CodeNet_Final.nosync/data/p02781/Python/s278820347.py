N = input()
L = len(N)
K = int(input())
dp = [[[0 for k in range(2)]for j in range(K+1)]for i in range(L+1)]
dp[0][0][0] = 1
for i in range(L):
    p = int(N[i])
    ni = i+1
    for j in range(K+1):
        for k in range(2):
            for d in range(10):
                nk = k
                nj = j
                if d != 0:
                    nj += 1
                if nj > K:
                    continue
                if nk == 0:
                    if d > p:
                        continue
                    if d < p:
                        nk = 1
                dp[ni][nj][nk] += dp[i][j][k]
print(dp[L][K][0]+dp[L][K][1])
