# Problem C - Half and Half

# input
A, B, C, X, Y = map(int, input().split())

# initialization
min_count = min(X, Y)
max_count = max(X, Y)
dp = [0] * (max_count + 1)

# dynamic programming
for i in range(1, min_count+1):
    dp[i] = min(A+B+dp[i-1], C*2+dp[i-1])

if X>Y:
    for i in range(min_count+1, max_count+1):
        dp[i] = min(A+dp[i-1], C*2+dp[i-1])
elif Y>X:
    for i in range(min_count+1, max_count+1):
        dp[i] = min(B+dp[i-1], C*2+dp[i-1])

# output
print(dp[max_count])
