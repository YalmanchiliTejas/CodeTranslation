N = int(input())
A = list(map(int, input().split()))

mod = 10**9+7

tmp = 0
for i in range(N):
    tmp += A[i]
    tmp = tmp % mod
all = (tmp % mod)**2
all = all % mod

tmp = 0
for i in range(N):
    tmp += (A[i]* A[i]) % mod
di = tmp % mod

ans = all - di
ans *= (mod + 1) // 2
ans %= mod

print(ans)