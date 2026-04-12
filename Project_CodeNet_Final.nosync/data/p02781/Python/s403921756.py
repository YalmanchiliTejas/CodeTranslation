s = input()
n = len(s)
K = int(input())

# dp[i][j][k]
# i : 桁数
# j : 非0を使った数
# k : そこまでの桁がs（指定された最大値）と一致しているか？、0なら一致してない、1なら一致してる
dp = [[[0 for i in range(2)] for j in range(4)] for k in range(105)]

# i = 0は、与えられた整数の一つ左の桁（上位の桁）に０があると仮定した時に
# そのパターンは１つしかない状態を持たない（i=0, j=0, k=1）ため初期値を設定している
dp[0][0][1] = 1

# debug_msg = "dp[{}][{}][{}] = {}"
for i in range(n):
  for j in range(4):
    for k in range(2):
      # sのi桁目を取得
      nd = int(s[i])
      # 各桁について0~9のパターンを考える
      for d in range(10):
        ni = i + 1
        nj = j
        nk = k
        if (d != 0): nj += 1
        if (nj > K): continue
        if (k == 1):
          if (d > nd): continue
          if (d < nd): nk = 0
        dp[ni][nj][nk] += dp[i][j][k]
        # print(debug_msg.format(ni, nj, nk, dp[ni][nj][nk]))

res = dp[n][K][0] + dp[n][K][1]
print(res)