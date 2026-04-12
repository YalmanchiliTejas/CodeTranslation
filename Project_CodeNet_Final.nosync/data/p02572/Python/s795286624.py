#-------------------------------------------------------------------
MOD = 10**9+7
#-------------------------------------------------------------------

N = int(input())
A = [int(i) for i in input().split()]

from itertools import accumulate
B = list( accumulate(A) )

ans = 0
for i in range(N-1):
  ans += ((B[-1]-B[i]) % MOD) * (A[i] % MOD)
  ans %= MOD

print(ans % MOD)

