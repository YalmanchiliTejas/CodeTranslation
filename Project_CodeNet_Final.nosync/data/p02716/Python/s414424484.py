N = int(input())
A = [int(x) for x in input().split()]
totalChooseNum = N // 2
dp = {0 : 0}
for i in range(0, N):
    ai = A[i]
    canChooseNum = (N - i + 1) // 2
    mustChooseNum = max(totalChooseNum - canChooseNum, 0)
    next = {}
    for j in range(mustChooseNum, N):
        if j > 0 and (2 * (j - 1)) in dp:
            next[2 * j + 1] = dp[2 * (j - 1)] + ai
        if 2 * j in dp:
            if 2 * j + 1 in dp:
                next[2 * j] = max(dp[2 * j] , dp[2 * j + 1])
            else:
                next[2 * j] = dp[2 * j]
        elif 2 * j + 1 in dp:
            next[2 * j] = dp[2 * j + 1]
        else:
            break
    dp = next
result = max(dp[totalChooseNum * 2] , dp[totalChooseNum * 2 + 1])
print(result)
