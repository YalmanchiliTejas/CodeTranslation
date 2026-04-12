K = int(input())
D = int(input())
L = len(str(K))
k = str(K)

dp = [[[0 for _ in range(2)] for _ in range(D)] for _ in range(L+1)]
dp[0][0][0] = 1

mod = 10 ** 9 + 7

for i in range(L):
    for sum in range(D):
        for sml in range(2):
            if sml == 1:
                for d in range(10):
                    dp[i+1][(d+sum)%D][1] += dp[i][sum][1]
                    dp[i+1][(d+sum)%D][1] %= mod
            elif sml == 0:
                lim = int(k[i])
                for d in range(lim):
                    dp[i+1][(d+sum)%D][1] += dp[i][sum][0]
                    dp[i+1][(d+sum)%D][1] %= mod
                dp[i+1][(lim+sum)%D][0] += dp[i][sum][0]
                dp[i+1][(lim+sum)%D][0] %= mod

ans = dp[L][0][0] + dp[L][0][1] - 1
ans %= mod

print(ans)