# C - Sum of product of pairs
import numpy as np

N = int(input())
A = list(int(a) for a in input().split())
MOD = 10**9 + 7
A = np.array(A)
csA = np.zeros((N+1), np.int64)
for i in range(N):
    csA[i+1] = (csA[i] + A[i]) % MOD
    
ans = 0
for i in range(N-1):
    ans += (A[i] * (csA[N] - csA[i+1])) % MOD
print(ans%MOD)