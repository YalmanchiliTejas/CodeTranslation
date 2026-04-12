_ = input()
A = list(map(int, input().split()))
mod = 10**9 + 7

s = 0
a = 0
for _a in A:
  s += _a * a
  a = (a + _a) % mod
print(s % mod)
