n = int(input())
a = list(map(int, input().split()))

ans = 0
mod = 10**9+7

S = sum(a)

for i in range(n-1):
    S -= a[i]
    ans += a[i]*S
    ans %= mod
print(ans)
