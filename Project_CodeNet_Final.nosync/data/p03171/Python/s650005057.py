import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

N = int(input())
a = list(map(int, input().split()))

INF = 10**18
dp = [[INF] * N for _ in range(N)]

# def calc(i, j, t):
#     if dp[i][j] != INF:
#         return dp[i][j]
#     if t == 0:
#         if i == j:
#             dp[i][j] = a[i]
#         else:
#             dp[i][j] = max(calc(i+1, j, 1) + a[i], calc(i, j-1, 1) + a[j])
#     else:
#         if i == j:
#             dp[i][j] = -a[i]
#         else:
#             dp[i][j] = min(calc(i+1, j, 0) - a[i], calc(i, j-1, 0) - a[j])
#     return dp[i][j]

# print(calc(0, N-1, 0))

for l in range(N):
    t = (N-l) % 2
    for i in range(N-l):
        j = i + l
        if t == 1:
            if l == 0:
                dp[i][j] = a[i]
            else:
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j])
        else:
            if l == 0:
                dp[i][j] = -a[i]
            else:
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j])
print(dp[0][N-1])