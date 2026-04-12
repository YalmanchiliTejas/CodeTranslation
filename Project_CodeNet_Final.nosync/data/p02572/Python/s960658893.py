import numpy as np
n = int(input())
A = np.array(list(map(int, input().split())),dtype=np.longlong)
mod = 7+10**9
cs = 0
for a in A:
    cs += a
    cs %= mod
cumsum = np.mod(np.cumsum(A),mod)
rev = -1*(cumsum-cs)
ans = 0
for i in range(n-1):
    ans += rev[i]*A[i]
    ans %= mod
print(ans)