import numpy as np

n = int(input())
a = np.array([int(x) for x in input().split()])
mod = 10**9+7
mod_sum = 0
a_sum = sum(a)
for i in range(n-1):
    a_sum -= a[i]
    mod_sum += (a[i] % mod) * (a_sum % mod) % mod

print(mod_sum%mod)