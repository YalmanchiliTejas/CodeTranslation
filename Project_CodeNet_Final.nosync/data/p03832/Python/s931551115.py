import sys
input = sys.stdin.readline
N, A, B, C, D = map(int, input().split())
dp = [[0] * (B + 1) for _ in range(N + 1)]
mod = 10 ** 9 + 7

class Factorial:
  def __init__(self, n, mod):
    self.f = [1]
    for i in range(1, n + 1):
      self.f.append(self.f[-1] * i % mod)
    self.i = [pow(self.f[-1], mod - 2, mod)]
    for i in range(1, n + 1)[: : -1]:
      self.i.append(self.i[-1] * i % mod)
    self.i.reverse()
  def factorial(self, i):
    return self.f[i]
  def ifactorial(self, i):
    return self.i[i]
  def combi(self, n, k):
    return self.f[n] * self.i[n - k] % mod * self.i[k] % mod

f = Factorial(1000 * 1000, mod)
dp[0][A - 1] = 1
for i in range(N):
  for k in range(A - 1, B):
    x = k + 1
    t = 1
    for j in range(1, C): t = t * f.combi(x * j, x) % mod
    for j in range(C, D + 1):
      if i + x * j <= N:
        t = t * f.combi(x * j, x) % mod
        dp[i + x * j][x] += dp[i][k] * f.combi(N - i, x * j) % mod * t % mod * f.ifactorial(j) % mod
        dp[i + x * j][x] %= mod
      else: break
      #print(j, t, dp)
    dp[i][x] += dp[i][k]
    dp[i][x] %= mod
    #print(dp)

res = 0
for k in range(A, B + 1):
  res += dp[-1][k]
  res %= mod
print(res)