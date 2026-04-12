import numpy as np

mod = 10**9+7
N = int(input())
A = np.array([int(i) for i in input().split()])

sum = A.sum() % mod

#B = np.square(A)
#sum2 = B.sum() % mod

sum2 = 0

for x in A:
  sum2 += x**2
  sum2 %= mod

ans = (sum**2 - sum2) % mod

if ans%2==1 : ans += mod
ans //= 2
ans %= mod
print(int(ans))
