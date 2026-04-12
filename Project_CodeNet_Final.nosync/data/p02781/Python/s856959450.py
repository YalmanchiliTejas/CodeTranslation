
# 桁DP問題
N = int(input())
K = int(input())

dp = [[[0,0] for _ in range(4)] for _ in range(101)]

dp[0][0][0] = 1

# i = Nの●桁目
# j = 0以外の数字を何回利用しているか
# k == 0 Nを超えないように注意が必要
# k == 1 N以下が保証されている

keta = len(str(N))
for i in range(keta):
  for j in range(4):
    for k in range(2):
      num = int(str(N)[i])

      for n in range(10):
        ni, nj, nk = i+1, j, k

        if n != 0:
          nj += 1 # 0以外の数字を利用した数が増えた
        if nj > K: 
          continue # すでにKを使い切っているときはカウントしない
        if k == 0:
          if n > num:
            continue # Nを超えているので飛ばす
          if n < num:
            nk = 1 # 何でもOK

        dp[ni][nj][nk] += dp[i][j][k]

print(dp[keta][K][0] + dp[keta][K][1])