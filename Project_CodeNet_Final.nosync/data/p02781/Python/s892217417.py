N = input()
K = int(input())

# dp[i][j][k]:問題の条件を満たす数の個数
# i桁目まで決定している。
# 非0の桁がすでにj個ある。
# k=0:i桁目までNと一致。k=1:すでにN以下であることが決まっている。

dp = [[[0 for _ in range(2)] for _ in range(4)] for _ in range(len(N)+1)]
dp[0][0][0] = 1
for i in range(len(N)):
  n = int(N[i])
  for j in range(4):
    for k in range(2):
      for d in range(10): # d:i+1桁目の数字
        # ni,nj,nk:次の遷移先
        ni = i+1
        nj = j
        nk = k
        if d > 0:
          nj += 1
        if nj > K:
          continue
        if k == 0:
          if d > n:
            continue
          if d < n:
            nk = 1
        dp[ni][nj][nk] += dp[i][j][k]

print(dp[len(N)][K][0]+dp[len(N)][K][1])
