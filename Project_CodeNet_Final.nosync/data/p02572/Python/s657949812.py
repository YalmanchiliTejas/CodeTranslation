N = int(input())
A = list(map(int, input().split()))

ans = 0
u = 0
mod = 10**9+7
for i in range(N) :
    ans += A[i] * u % mod
    u += A[i] % mod
print(ans % mod)