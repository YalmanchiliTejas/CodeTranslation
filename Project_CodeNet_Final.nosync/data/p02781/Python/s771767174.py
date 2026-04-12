n = input()
K = int(input())


dp = [[[0] * (K + 2) for _ in range(2)] for _ in range(len(n) + 1)]
# positon, is_less, k-nums
dp[0][0][0] = 1

for i in range(len(n)):
    for j in range(2):
        digit = 9 if j else int(n[i])
        for k in range(K + 1):
            for d in range(digit + 1):
                if d != 0:
                    dp[i + 1][j or d < digit][k + 1] += dp[i][j][k]
                else:
                    dp[i + 1][j or d < digit][k] += dp[i][j][k]

ans = 0
for j in range(2):
    ans += dp[-1][j][K]
print(ans)