N = int(input())
A = list(map(int,input().split()))

mod = 10**9+7

su = sum(A)

ans = su * su
for i in range(N):
    ans -= A[i] * A[i]
    ans %= mod

print((ans * 500000004)%mod)