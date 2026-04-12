n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
array_sum = sum(a) % mod
ans = 0
for i in range(n):
    ans += a[i] * array_sum % mod
    ans -= a[i] * a[i] % mod
print((ans * pow(2,-1,mod)) % mod)