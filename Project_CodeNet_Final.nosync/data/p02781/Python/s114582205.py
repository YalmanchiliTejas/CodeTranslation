NN = 2020202
MOD = 10**9+7
INF = float("inf")

N = input()
K = int(input())
len_n = len(N)

dp0 = [[0] * 4 for _ in range(len_n)]  # not fixed
dp1 = [[0] * 4 for _ in range(len_n)]  # fixed
dp0[0][1] = 1
dp1[0][1] = int(N[0]) - 1
for i in range(len_n):
    dp1[i][0] = 1

for i in range(1, len_n):
    cur = int(N[i])
    for k in range(1, 4):
        if cur == 0:
            dp0[i][k] = dp0[i - 1][k]
            dp1[i][k] = dp1[i - 1][k] + 9*dp1[i - 1][k-1]

        else:
            dp0[i][k] = dp0[i - 1][k - 1]
            dp1[i][k] = dp1[i - 1][k] + 9*dp1[i - 1][k-1] + (cur - 1)*dp0[i - 1][k-1] + dp0[i - 1][k]

print(dp0[-1][K] + dp1[-1][K])