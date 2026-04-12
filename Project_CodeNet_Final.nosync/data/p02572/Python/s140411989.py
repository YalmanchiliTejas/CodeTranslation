import numpy as np

N = int(input())
A = np.array(list(map(int, input().split())))
ans = 0
Asum = [0 for _ in range(N)]
Asum[0] = A[0]%(10**9+7) 
for i in range(1,N):
  Asum[i] = (Asum[i-1] + A[i])%(10**9+7)
for i in range(N-1):
  ans += (A[i]*(Asum[N-1] - Asum[i]))%(10**9+7)
print(ans%(10**9+7))