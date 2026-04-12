import sys
input = sys.stdin.buffer.readline
sys.setrecursionlimit(1000000000)

N = int(input())
a = list(map(int, input().split()))

dp = [[float("inf")]*(N+1) for _ in range(N+1)]

for shift_i in range(N+1):
    for i in range(N+1):
        if i+shift_i >= N+1:
            continue
        if shift_i == 0:
            dp[i][i] = 0
        elif ((i+shift_i)-i)%2 == N%2: # 先手番
            dp[i][(i+shift_i)] = max(a[i] + dp[i+1][(i+shift_i)], a[(i+shift_i)-1] + dp[i][(i+shift_i)-1])
        else:
            dp[i][(i+shift_i)] = min(-a[i] + dp[i+1][(i+shift_i)], -a[(i+shift_i)-1] + dp[i][(i+shift_i)-1])

print(dp[0][N])