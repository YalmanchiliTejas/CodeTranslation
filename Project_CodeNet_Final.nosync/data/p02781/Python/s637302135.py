N = input()
K = int(input())

L = len(N)

# dp[i][j][k]
# i: 決定した桁数(上から)
# j: 0の個数
# k: N未満確定フラグ
dp = [[[0] * 2 for _ in range(5)] for _ in range(110)]

dp[0][0][0] = 1

# 配るDP
for i in range(L):
    S = int(N[i])
    for j in range(K+1):
        for k in range(2):
            # d: 次の桁
            for d in range((9 if k else S) + 1):
                dp[i+1][j + (d != 0)][k | (d < S)] += dp[i][j][k]

ans = dp[L][K][0] + dp[L][K][1]
print(ans)