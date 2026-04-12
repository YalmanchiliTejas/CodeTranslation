import numpy as np
MOD = 10**9+7

N = int(input())
A = np.array(list(map(int, input().split())))
A = A % MOD

AS = []
s = 0
for a in range(len(A)):
  s = (s + A[a]) % MOD
  AS.append(s)
AS = np.array(AS)

s = 0
for i in range(len(A)-1):
  s = (A[i] * ((AS[N-1]-AS[i])) % MOD + s) % MOD
  
print(s)