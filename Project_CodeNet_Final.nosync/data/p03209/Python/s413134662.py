import math
N, X = map(int, input().split())

dp = [0] * (N + 1)
p_dp = [0] * (N + 1)
dp[0] = 1
p_dp[0] = 1
for i in range(1, N + 1):
    dp[i] = dp[i - 1] * 2 + 3
    p_dp[i] = p_dp[i - 1] * 2 + 1
patties = p_dp[N]
burger_len = dp[N]

tmp = X
middle = -(-dp[N]//2)
n = N - 1
ans = 0
while True:
    #print("middle:", middle)
    #print("tmp:", tmp)
    if tmp == 1:
        if middle == 1:
            ans += 1
        break
    if tmp == middle:
        ans += p_dp[n] + 1
        break
    if tmp == dp[n + 1]:
        ans += p_dp[n] * 2 + 1
        break
    if 1 < tmp < middle:
        middle = -(-dp[n]//2)
        tmp -= 1
        n -= 1
    if middle < tmp < dp[n + 1]:
        tmp -= middle
        middle = -(-dp[n]//2)
        ans += p_dp[n] + 1
        n -= 1
print(ans)
