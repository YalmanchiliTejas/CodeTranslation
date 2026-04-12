import numpy as np

#A = list(map(int,input().split()))

N = int(input())
A = list(map(int,input().split()))


ans = 0
mod = 10**9 + 7
s = 0

for i in range(N):
    s += A[i]
    s = s%mod

for i in range(N-1):
    s = (s-A[i])%mod
    ans += (A[i] * s)%mod
    ans = ans % mod

print(ans%mod)
