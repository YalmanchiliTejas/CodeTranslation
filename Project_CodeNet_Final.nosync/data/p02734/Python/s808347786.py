N, S = map(int, input().split())
MOD = 998244353
A = list(map(int, input().split()))

# dp[i][s] : Rをiに固定した時に、和がsとなる整数列の組が何回現れるか
dp = [[0]*(S+1) for i in range(N+1)]
ans = 0

for i, a in enumerate(A, 1):
  for s in range(S+1):
    dp[i][s] = dp[i-1][s]
    dp[i][s] += s==0 or s==a
    if s >= a:
      dp[i][s] = (dp[i][s] + dp[i-1][s-a]) % MOD
  ans = (ans + dp[i][-1]) % MOD

print(ans)