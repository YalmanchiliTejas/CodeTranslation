n = int(input())
a = list(map(int, input().split()))
mod = pow(10, 9) + 7
ans = 0
s = sum(a) % mod
for i in range(n):
    s -= a[i] % mod
    ans += (a[i] * s) % mod
    ans %= mod
print(ans)