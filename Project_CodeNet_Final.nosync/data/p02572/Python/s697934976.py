n = int(input())
a = list(map(int, input().split()))
mod = int(1e9 + 7)
ans, x = 0, 0
for i in range(n):
    ans += a[i]*x
    x += a[i]
print(ans%mod)