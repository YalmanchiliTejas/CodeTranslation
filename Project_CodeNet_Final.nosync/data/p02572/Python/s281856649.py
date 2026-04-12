n = int(input())
a = [int(x) for x in input().split()]

s = sum(a)
ans = 0
mod = 10 ** 9 + 7

for i in range(n-1):
    s -= a[i]
    ans += a[i] * s % mod

ans = ans % mod
print(ans)