n = int(input())
a = list(map(int, input().split()))

mod = 10**9+7
tmp = sum(a)
d = []
for i in range(n-1):
    tmp -= a[i]
    d.append(tmp%mod)
ans = 0
for i in range(n-1):
    ans += a[i]*d[i]%mod
    ans %= mod

print(ans)