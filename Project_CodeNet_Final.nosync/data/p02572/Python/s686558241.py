read = lambda: list(map(int, input().split()))
n = int(input())
a = read()

s = sum(a)
mod = 10 ** 9 + 7
ans = 0

for i in range(n - 1):
    s -= a[i]
    ans += a[i] * s
    ans %= mod
print(ans)