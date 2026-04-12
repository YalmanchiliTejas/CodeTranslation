n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
a0 = sum(a[1:])
ans = 0

for i in range(n-1):
    ans += (a0*a[i])%mod
    ans %= mod
    a0 -= a[i+1]
print(ans)
