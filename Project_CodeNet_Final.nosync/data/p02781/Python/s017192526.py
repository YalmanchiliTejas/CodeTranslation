S = input()
K = int(input())

l = len(S)

MOD = 1000000007

# [桁数][未満][0でない数の合計数]
dp = [[[0] * (l + 1) for _ in range(2)] for _ in range(l + 1)]


# 初期化
dp[0][False][0] = 1

for i in range(l):
    cur = int(S[i])

    for j in range(i + 1):
        # true -> true
        for k in range(10):
            if k == 0:
                dp[i + 1][True][j] += dp[i][True][j]
            else:
                dp[i + 1][True][j + 1] += dp[i][True][j]

        # false -> true
        for k in range(cur):
            if k == 0:
                dp[i + 1][True][j] += dp[i][False][j]
            else:
                dp[i + 1][True][j + 1] += dp[i][False][j]

        # false -> false
        if cur == 0:
            dp[i + 1][False][j] += dp[i][False][j]
        else:
            dp[i + 1][False][j + 1] += dp[i][False][j]

if K > l:
    print(0)
else:
    print(dp[l][True][K] + dp[l][False][K])
