import sys
input = sys.stdin.readline
N, M, K = map(int, input().split())
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

f = Factorial(N * M, mod)
t = f.combi(N * M - 2, K - 2)

res = 0
for d in range(1, M):
  x = N ** 2 % mod * (M - d) % mod
  res += x * d % mod
  res %= mod
  #print(x)
for d in range(1, N):
  y = M ** 2 % mod * (N - d) % mod
  res += y * d % mod
  res %= mod
#print(res, t)
print(res * t % mod)