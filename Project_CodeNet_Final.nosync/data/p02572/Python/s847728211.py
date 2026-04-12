n = int(input())
a = list(map(int, input().split()))
mod = 10 ** 9 + 7

ans = (sum(a) % mod) ** 2
for i in range(n):
    ans -= a[i] ** 2
    ans %= mod
if ans % 2 == 0:
    print(ans // 2)
else:
    print((ans + mod) // 2)