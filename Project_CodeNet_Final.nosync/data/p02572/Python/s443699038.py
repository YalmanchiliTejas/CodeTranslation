import numpy as np

N = int(input())
A = list(map(int, input().split()))

A = np.array(A)
MOD = 10**9 + 7

ruisekiwa = np.zeros(N, dtype='int')
for i in range(1, N):
    ruisekiwa[i] = ruisekiwa[i-1] + A[i]

res = 0
for i in range(N-1):
    # res += np.sum(np.mod(A[i] * A[i+1:], MOD))
    res += (ruisekiwa[N-1] - ruisekiwa[i]) % MOD * A[i] % MOD
print(res % MOD)

# FIXME TLE