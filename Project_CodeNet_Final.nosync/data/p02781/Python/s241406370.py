N = input()
K = int(input())

len_N = len(N)

dp = [[[0 for _ in range(K + 2)] for _ in range(2)] for _ in range(len_N + 1)]
dp[0][0][0] = 1 # position, is_less, num_of_zeros
for i in range(len_N):
    for j in range(2):
        for k in range(K + 1):
            lim = 9 if j else int(N[i])
            for d in range(lim + 1):
                if d != 0:
                    dp[i + 1][j or d < lim][k + 1] += dp[i][j][k]
                else:
                    dp[i + 1][j or d < lim][k] += dp[i][j][k]
ans = 0
for i in range(2):
    ans += dp[len_N][i][K]
print(ans)
# for d in dp:
#     print(d)