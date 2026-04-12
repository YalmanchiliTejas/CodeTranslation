N = input()
N_digit = len(N)
K = int(input())

# dp[i][k] := i番目みて、0でない数がk個出現しているときの通り数
# dp0 := N以下であることが未確定, dp1 := N以下であることが確定
dp0 = [[0] * (K + 1) for i in range(N_digit + 1)]
dp1 = [[0] * (K + 1) for i in range(N_digit + 1)]
dp0[0][0] = 1

for i, n in enumerate(N):
    for k in range(K + 1):
        if n == '0':
            dp0[i + 1][k] += dp0[i][k]
            dp1[i + 1][k] += dp1[i][k]
            if k < K:
                dp1[i + 1][k + 1] += 9 * dp1[i][k]

        else:
            if k < K:
                dp0[i + 1][k + 1] += dp0[i][k]
                dp1[i + 1][k + 1] += (int(n) - 1) * dp0[i][k]
                dp1[i + 1][k + 1] += 9 * dp1[i][k]

            dp1[i + 1][k] += dp0[i][k]
            dp1[i + 1][k] += dp1[i][k]

print(dp0[-1][K] + dp1[-1][K])
