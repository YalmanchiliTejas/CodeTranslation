n, *a = map(int, open(0).read().split())
mod = 10 ** 9 + 7

s = [0] * n

for i in range(n - 1, 0, -1):
    s[i - 1] = s[i] + a[i]

ans = 0
for i in range(n):
    ans = (ans + a[i] * (s[i])) % mod
print(ans)
