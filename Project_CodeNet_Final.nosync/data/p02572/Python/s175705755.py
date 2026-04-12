n = int(input())
a = list(map(int, input().split()))
l = [0]
mod = 10 ** 9 + 7
s = sum(a)
cur = 0
ans = 0
for i in range(n):
    cur += a[i]
    ans += (a[i] * (s - cur)) % mod
    ans %= mod
print(ans)