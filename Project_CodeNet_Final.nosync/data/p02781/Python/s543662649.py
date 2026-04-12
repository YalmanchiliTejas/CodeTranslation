import sys
read = sys.stdin.read

n, k = map(int, read().split())


def count(d, k):
  if k == 0:
    return 1
  elif k == 1:
    return d
  elif k == 2:
    return d * (d - 1) // 2
  else:
    return d * (d - 1) * (d - 2) // 6


def solve(n, k):
  digit = len(str(n))
  if digit == 0 and k > 0:
    return 0
  if k == 0:
    return 1
  res = 0
  if digit > k:
    res += count(digit - 1, k) * (9 ** k)
  a = 10 ** (digit - 1)
  d, mod = n // a, n % a
  res += count(digit - 1, k - 1) * (9 ** (k - 1)) * (d - 1)
  res += solve(mod, k - 1)
  return res


print(solve(n, k))