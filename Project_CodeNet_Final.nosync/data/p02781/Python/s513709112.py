S = input()
K = int(input())

length = len(S)
dp = [[[0] * (K + 1) for _ in range(2)] for _ in range(length + 1)]
dp[0][0][0] = 1

for i in range(1, length + 1):
    for j in range(2):
        for k in range(K + 1):
            os = int(S[i - 1])
            for x in range(10):
                ni = i
                nj = j
                nk = k
                if x != 0:
                    nk += 1
                if nk > K:
                    continue
                if j == 0:
                    if x > os:
                        continue
                    elif x < os:
                        nj = 1
                dp[ni][nj][nk] += dp[i - 1][j][k]

ans = dp[length][0][K] + dp[length][1][K]
print(ans)
