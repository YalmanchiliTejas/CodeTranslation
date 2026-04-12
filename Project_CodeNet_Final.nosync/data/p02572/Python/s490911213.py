import numpy as np
MOD = 10**9+7
n = input()
a = list(map(int, input().split()))
ans = 0
cum_a = np.cumsum(a[::-1])
cum_a = cum_a[::-1]
for i, ai in enumerate(a):
  if i == len(a)-1:
    continue
  sum_aj = cum_a[i+1]
  ans += ((ai%MOD)*(sum_aj%MOD))%MOD

print(ans%MOD)