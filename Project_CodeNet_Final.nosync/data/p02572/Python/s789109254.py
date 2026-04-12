n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
sum = sum(a)

ans = 0
for i in range(n-1):
    sum -= a[i]
    ans += a[i]*(sum%mod)
print(ans%mod)