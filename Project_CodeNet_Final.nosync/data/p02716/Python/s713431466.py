#f dp
n = int(input())
a = list(map(int, input().split()))
DIM, PER = 0, 1
MIN, MAJ = 0, 1
# pick from 0~i
# j = DIM or PER if i is odd, MIN or MAJ otherwise
dp = [[None, None] for _ in range(n)]
dp[0] = [0, a[0]]
dp[1] = [0, max(a[0], a[1])]
for i in range(2, n):
    if i % 2 == 0:
        dp[i][MIN] = max(dp[i - 2][MIN] + a[i], dp[i - 1][PER])
        dp[i][MAJ] = dp[i - 2][MAJ] + a[i]
    else:
        dp[i][DIM] = max(dp[i - 2][DIM] + a[i], dp[i - 1][MIN])
        dp[i][PER] = max(dp[i - 2][PER] + a[i], dp[i - 1][MAJ])
if n % 2 == 0:
    print(dp[n - 1][PER])
else:
    print(dp[n - 1][MIN])