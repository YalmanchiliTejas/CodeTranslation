import numpy as np

N = int(input())
A = list(map(int, input().split()))

mod = 1000000007
res = np.cumsum(A, dtype=np.float64)
ans = 0

for i in range(N-1):
    S = (int(res[N-1])-int(res[i])) % mod
    ans += A[i]*S
    ans %= mod

print(int(ans))