import sys
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
mod = 10 ** 9 + 7
sm = sum(a)
res = 0
div = pow(2, mod - 2, mod)
for x in a:
  res += x * (sm - x)
  res %= mod
print(res * div % mod)