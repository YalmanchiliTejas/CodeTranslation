N = int(input())
K = int(input())

X = str(N)

dp = [[[0] * (K+1) for _ in range(2)] for _ in range(len(X)+1)]
dp[0][0][0] = 1

for i in range(len(X)):
    digit = int(X[i])
    for j in range(2):
        for k in range(K+1):
            for d in range(10 if j == 1 else digit+1):
                if k + int(d != 0) <= K:
                    dp[i+1][j | (d < digit)][k + (d!=0)] += dp[i][j][k]
print(dp[-1][0][-1]+dp[-1][1][-1])