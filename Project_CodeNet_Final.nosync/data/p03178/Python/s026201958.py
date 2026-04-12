import sys
fin = sys.stdin.readline


MOD = 10**9 + 7
K = [int(elem) for elem in fin()[:-1]]
D = int(fin())

dp = [[0] * 2 for _ in range(D)]
dp[0][1] = 1

for bound in K:
    next_dp = [[0] * 2 for _ in range(D)]
    for num in range(10):
        for d in range(D):
            next_reminder = (num + d) % D
            if num < bound:
                next_dp[next_reminder][0] += (dp[d][0] + dp[d][1])
            elif num == bound:
                next_dp[next_reminder][0] += dp[d][0]
                next_dp[next_reminder][1] += dp[d][1]
            else:
                next_dp[next_reminder][0] += dp[d][0]
            next_dp[next_reminder][0] %= MOD
            next_dp[next_reminder][1] %= MOD
    # import pdb; pdb.set_trace()
    dp = next_dp

res = dp[0][0] + dp[0][1] - 1
print(res) if res >= 0 else print(res + MOD)
