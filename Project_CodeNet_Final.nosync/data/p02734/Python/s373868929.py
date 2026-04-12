import sys
readline = sys.stdin.readline

DIV = 998244353
N,S = map(int,readline().split())
A = list(map(int,readline().split()))

# ある数の取り得る状態は以下
# (1)Lの区間がまだ開始していない
# (2)L-Rの区間に含まれ、和に使われている
# (3)L-Rの区間に含まれ、和に使われていない
# (4)Rの区間が終了している

# dp[i][j][k] = i - 1個目まで処理したときに、区間の開始状況がjで、総和がkになっている個数
dp = [[[0] * (S + 1) for j in range(3)] for i in range(N + 1)]
dp[0][0][0] = 1

for i in range(N):
  for k in range(S + 1):
    # (1)まだ区間が開始していない場合
    dp[i + 1][0][k] += dp[i][0][k]
    dp[i + 1][0][k] %= DIV

    # (2)区間に含まれ、和に使われている
    if k + A[i] <= S:
      dp[i + 1][1][k + A[i]] += dp[i][0][k]
      dp[i + 1][1][k + A[i]] += dp[i][1][k]
      dp[i + 1][1][k + A[i]] %= DIV

    # (3)区間に含まれ、和に使われていない
    dp[i + 1][1][k] += dp[i][0][k]
    dp[i + 1][1][k] += dp[i][1][k]
    dp[i + 1][1][k] %= DIV

    # (4)区間が終了している
    dp[i + 1][2][k] += dp[i][2][k]
    dp[i + 1][2][k] += dp[i][1][k]
    dp[i + 1][2][k] %= DIV

print((dp[-1][1][-1] + dp[-1][2][-1]) % DIV)
