N, S = map(int, input().split())
a = list(map(int, input().split()))

dp1 = [0] * (S + 1)
ans = 0
for i in range(N):
  dp1[0] += 1
  dp2 = [0] * (S + 1)
  for j in range(S+1):
    dp2[j] += dp1[j]
    if j + a[i] <= S:
      dp2[j+a[i]] += dp1[j]
  dp1 = dp2[:]
  ans += dp1[-1]
  ans = ans % 998244353
print(ans)