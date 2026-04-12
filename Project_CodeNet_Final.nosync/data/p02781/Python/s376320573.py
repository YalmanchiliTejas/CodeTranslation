from operator import mul
from functools import reduce
from math import floor, log
from itertools import combinations, product

S = input()
N = int(S)
K = int(input())

S_len = len(S)
N_first = int(S[0])

def combinations_count(n, r):
  if n < r:
    return 0
  if r == 0:
    return 1
  r = min(r, n - r)
  numer = reduce(mul, range(n, n - r, -1), 1)
  denom = reduce(mul, range(1, r + 1), 1)
  return numer // denom

if K > S_len:
  print(0)
else:
  count = 0
  if K > 1:
    for l in combinations(range(1, S_len), K-1):
      for m in product('123456789', repeat=K-1):
        s = S[0] + '0' * (S_len - 1)
        for i in range(K-1):
          s = s[:l[i]] + m[i] + s[l[i]+1:]
        if int(s) <= N:
          count += 1
  else:
    count += 1
  count += (N_first-1) * combinations_count(S_len-1, K-1) * (9 ** (K-1))
  count += combinations_count(S_len-1, K) * (9 ** K)
  print(count)
