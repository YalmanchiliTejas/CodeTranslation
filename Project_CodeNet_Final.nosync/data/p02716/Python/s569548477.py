INF = 10 ** 15

N = int(input())
As = list(map(int, input().split()))
As.append(-INF)

INF = 10 ** 15
dp = [[-INF] * (N//2) for _ in range(3)]
dp[0][0] = As[0]
dp[1][0] = As[1]
dp[2][0] = As[2]

for i in range(1, N//2):
    dp[0][i] = dp[0][i-1] + As[2*i]
    dp[1][i] = max(dp[0][i-1], dp[1][i-1]) + As[2*i+1]
    dp[2][i] = max(dp[0][i-1], dp[1][i-1], dp[2][i-1]) + As[2*i+2]

if N % 2 == 0:
    print(max(dp[0][-1], dp[1][-1]))
else:
    print(max(dp[0][-1], dp[1][-1], dp[2][-1]))

