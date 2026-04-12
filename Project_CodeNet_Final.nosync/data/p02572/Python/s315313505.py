N = int(input())

A = list(map(int, input().split()))
mod = 10**9 + 7

s = sum(A) % mod
s += mod
ss = 0
for i in range(N):
    ss += A[i]**2 % mod

ss = ss % mod
if (s**2 - ss) % 2 == 1:
    ss -= mod

print((((s**2) - ss) // 2) % mod)