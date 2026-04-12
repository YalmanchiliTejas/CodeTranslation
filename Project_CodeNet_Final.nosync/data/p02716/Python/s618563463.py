N = int(input())
A = list(map(int, input().split()))

dp_g = A[1]
dp_k = A[0]
dp = [0, max(dp_g, dp_k)]

for i in range(2, N):
    if i % 2 == 1:
        dp_g = max(dp_k, dp_g) + A[i]
        dp_k += A[i - 1]
        dp.append(max(dp_g, dp_k))
    elif i % 2 == 0:
        dp.append(max(dp[i - 1], dp[i - 2] + A[i]))

print(dp[N - 1])