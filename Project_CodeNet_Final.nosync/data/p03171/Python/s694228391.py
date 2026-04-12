n = int(input())
a = list(map(int, input().split()))
dp = [[0] * n for _ in range(n)]
for i in range(n):
    dp[i][i] = a[i]

for i in range(n - 2, -1, -1):
    for j in range(i + 1, n):
        dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1])

print(dp[0][n - 1])

# 下記提出と全く同じ内容で提出します
# https://atcoder.jp/contests/dp/submissions/6590284

# これまでの連投で参考にしていたコード
# ほぼ同じ内容で提出しているつもりなのに、速度差が一向に縮まらない

# maxの引数の順番が自分と違うのが速度差の原因？
