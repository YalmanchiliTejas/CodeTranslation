import sys

stdin = sys.stdin

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(stdin.readline().rstrip())
nm = lambda: map(int, stdin.readline().split())
nl = lambda: list(map(int, stdin.readline().split()))

n = ns()
k = ni()
dp = [[[0]*2 for _ in range(k+1)] for _ in range(len(n)+1)]
dp[0][0][0] = 1
for i in range(len(n)):
    x = int(n[i])
    for j in range(k):
        dp[i+1][j+1][1] += dp[i][j][1]*9
        dp[i+1][j][1] += dp[i][j][1]
        if x > 0:
            dp[i+1][j][1] += dp[i][j][0]
            dp[i+1][j+1][1] += dp[i][j][0]*(x-1)
            dp[i+1][j+1][0] += dp[i][j][0]
        else:
            dp[i+1][j][0] += dp[i][j][0]
    dp[i+1][k][1] += dp[i][k][1]
    dp[i+1][k][x>0] += dp[i][k][0]
print(sum(dp[len(n)][k]))
