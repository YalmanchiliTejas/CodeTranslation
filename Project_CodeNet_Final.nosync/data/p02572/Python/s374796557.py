n = int(input())
a = list(map(int, input().split()))
mod = 10**9 + 7
sa = [0] * (n + 1)
for i in range(n):
    sa[i + 1] = sa[i] + a[i]
ans = 0
for i in range(n - 1):
    temp = sa[i + 1] * a[i + 1] % mod
    ans += temp
    ans %= mod
print(ans)
