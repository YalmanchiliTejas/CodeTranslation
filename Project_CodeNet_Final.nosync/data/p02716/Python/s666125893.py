import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

n = int(readline())
inf = -float('inf')
a = list(map(int, readline().split())) + [inf] * 2
dp = [[inf] * 3 for _ in range(n + 4)]
for i in range(3):
    dp[0][i] = 0
for i, (bf, aa, af) in enumerate(zip(a, a[1:], a[2:])):
    dp[i + 4][2] = max(dp[i + 4][2], dp[i][0] + af)
    for j in range(1, 3):
        dp[i + 3][j] = max(dp[i + 3][j], dp[i][j - 1] + aa)
    for j in range(3):
        if dp[i + 2][j] != inf or j == 0:
            dp[i + 2][j] = max(dp[i + 2][j], dp[i][j] + bf)
if n % 2 == 0:
    print(max(dp[n + 1][1], dp[n][0]))
else:
    print(max(dp[n + 1][2], dp[n][1], dp[n - 1][0]))
