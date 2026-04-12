N = int(input())
A = list(map(int, input().split()))

mod = 10**9+7
sa = sum(A)%mod

ans = 0
for i in range(N):
    ans += (sa-A[i]) * A[i]
    ans %= mod

if ans%2== 1:
    ans += mod

print((ans//2)%mod)