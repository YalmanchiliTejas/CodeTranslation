mod = 10**9+7
N = int(input())
A = list(map(int,input().split()))

ans = 0
for i in range(N):
    ans += A[i]
    ans %= mod
ans = ans**2%mod

for i in range(N):
    ans -= A[i]**2
    ans %= mod

ans *= pow(2,mod-2,mod)
ans %= mod
print(ans)