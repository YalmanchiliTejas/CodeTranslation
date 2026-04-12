from itertools import accumulate
mod = 10**9 + 7
n, *A = map(int, open(0).read().split())
B = [b % mod for b in accumulate(A[::-1])][::-1][1:]
s = 0
for a, b in zip(A, B):
  s += a*b
  s %= mod
print(s)