K = input()
D = int(input())
dp = [[0] * D for _ in range(len(K))]
mod = 10 ** 9 + 7
#桁DP
#0 ~ K[0] - 1までの数をトップとする場合
for i in range(int(K[0])):
  dp[0][i % D] += 1
#tightは上限付近の制御に使う
#K[0]をトップとする場合がtight
#tightは上限ギリギリを攻める
tight = int(K[0]) % D
if len(K) > 1:
  for i in range(len(K) - 1):
    for j in range(D):
      for k in range(10):
        dp[i + 1][(j + k) % D] += dp[i][j]
        dp[i + 1][(j + k) % D] %= mod
    #Kを超えないようにしている
    for k in range(int(K[i + 1])):
      dp[i + 1][(tight + k) % D] += 1
    #上から(i + 1)桁まで見たもので、上限ギリギリのものの剰余
    tight = (tight + int(K[i + 1])) % D
#tightは最終的に上限の剰余に一致するので、0でないならその分を除く
print((dp[len(K) - 1][0] + (tight == 0) - 1) % mod)