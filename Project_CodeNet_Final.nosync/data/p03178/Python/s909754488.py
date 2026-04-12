# S - Digit Sum
k = input()
d = int(input())
n = len(k)
MOD = 10**9+7

# dp[i][j][l]
# i桁目までみたとき、
# j=0:k未満であることが確定していない。j=1:k未満であることが確定している。
# l:桁和のmod dがlである数の個数。

dp = [[[0 for _ in range(d)] for _ in range(2)] for _ in range(n+1)]
dp[0][0][0] = 1

for i in range(n):
  for j in range(d):
    # k未満であることが確定していれば、i桁目は0～9の数字がとれる。
    for l in range(10):
      dp[i+1][1][(j+l)%d] += dp[i][1][j]
      dp[i+1][1][(j+l)%d] %= MOD
    # k未満であることが確定していない場合、i桁目を0～k[i]-1にすればk未満であることが確定する。
    for l in range(int(k[i])):
      dp[i+1][1][(j+l)%d] += dp[i][0][j]
      dp[i+1][1][(j+l)%d] %= MOD
    # k未満であることが確定していない場合、i桁目をk[i]にすればk未満であることは確定しない。
    dp[i+1][0][(j+int(k[i]))%d] += dp[i][0][j]
    dp[i+1][0][(j+int(k[i]))%d] %= MOD
# 0が解答にカウントされているので、0の分を除くため-1する。
print((dp[n][0][0]+dp[n][1][0]-1)%MOD)
# print(dp)