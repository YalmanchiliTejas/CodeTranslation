n = int(input())
a = list(map(int, input().split()))
MOD = 10**9+7
ans = 0
plus = 0
for i in range(n-1):
    plus += a[n-i-1]
    plus %= MOD
    ans += a[n-i-2]*plus
    ans %= MOD
print(ans%MOD)