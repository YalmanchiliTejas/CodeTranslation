N=int(input())

A=list(map(int,input().split()))

# まず、Nが3以下のときはAの最大値を返して終了
if N<=3:
  print(max(A))
  exit(0)

# 通常は1つ先まで進むが、
# Nが奇数の場合は2マス
# Nが偶数の場合は1マス
# どこかで余計に進むことができる。この余計に進んだマス数を保持してDP

if N&1:
  # Nが奇数の場合は最大2マス飛ばす権利がある
  dp=[[-((10**9) * (10**5))-1]*3 for i in range(N)]

  dp[0][0] = A[0] # 最初のマス
  dp[1][1] = A[1] # 1マス使う権利を行使
  dp[2][2] = A[2] # 2マス使う権利を行使
  for i in range(N):
    if i+2<N:
      # 通常の2マス進み
      for j in range(3):
        if dp[i+2][j] < dp[i][j] + A[i+2]:
          dp[i+2][j] = dp[i][j] + A[i+2]
    if i+3<N:
      # 1マス飛ばしパターン
      for j in range(2):
        if dp[i+3][j+1] < dp[i][j] + A[i+3]:
          dp[i+3][j+1] = dp[i][j] + A[i+3]
    if i+4<N:
      # 2マス飛ばしパターン
      if dp[i+4][2] < dp[i][0] + A[i+4]:
        dp[i+4][2] = dp[i][0] + A[i+4]
  
  # 以下の3パターンを比較する
  # 2マスの権利を使わずに最後2マス残す
  # 1マスの権利を残して最後1マス残す
  # 権利なしで最後のマス
  ans = max(dp[N-3][0],dp[N-2][1],dp[N-1][2])
  print(ans)
  
else:
  # Nが偶数の場合は最大1マス飛ばす権利がある
  # Nが奇数の場合は最大2マス飛ばす権利がある
  dp=[[-((10**9) * (10**5))-1]*2 for i in range(N)]

  dp[0][0] = A[0] # 最初のマス
  dp[1][1] = A[1] # 1マス使う権利を行使
  for i in range(N):
    if i+2<N:
      # 通常の2マス進み
      for j in range(2):
        if dp[i+2][j] < dp[i][j] + A[i+2]:
          dp[i+2][j] = dp[i][j] + A[i+2]
    if i+3<N:
      # 1マス飛ばしパターン
      if dp[i+3][1] < dp[i][0] + A[i+3]:
        dp[i+3][1] = dp[i][0] + A[i+3]
  
  # 以下の2パターンを比較する
  # 1マスの権利を残して最後1マス残す
  # 権利なしで最後のマス
  ans = max(dp[N-2][0],dp[N-1][1])
  print(ans)
