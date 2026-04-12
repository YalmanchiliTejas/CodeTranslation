N = int(input())
K = int(input())
l = len(str(N))
dp = [[[0]*(K+1) for _ in range(2)] for _ in range(l+1)]
# dp[i][smaller][j]
# i: 調べている桁
# smaller: 未満フラグ(未満のとき1)
# j: 0以外の数がj回出た

dp[0][0][0] = 1
for i in range(l):
  n = int(str(N)[i])
  for j in range(2):
    for k in range(K+1):
      for m in range(10):
        # 今までは一致
        if j == 0 and m > n:
          continue
        if j == 0 and m == n:
          nj = 0 # 今回も一致
          if m == 0:
            nk = k # 0なら回数は増えない
          else:
            if k < K:
              nk = k + 1 # 0以外の数がK-1回以下しかでていないなら増やす
            else:
              nk = k
              continue
        if j == 0 and m < n:
          nj = 1
          if m == 0:
            nk = k
          else:
            if k < K:
              nk = k + 1
            else:
              nk = k
              continue

        # すでに未満
        if j == 1:
          nj = j
          if m == 0:
            nk = k
          else:
            if k < K:
              nk = k + 1
            else:
              nk = k
              continue

        dp[i+1][nj][nk] += dp[i][j][k]

print(dp[l][0][K]+dp[l][1][K])

