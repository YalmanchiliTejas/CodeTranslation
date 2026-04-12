n, s = map(int, input().split())
a = list(map(int, input().split()))

d = [[0 for _ in range(2)] for _ in range(s+1)]
mod = 998244353

for i in range(n):
    for j in reversed(range(s-a[i]+1)):
        d[j + a[i]][0] += d[j][0]
        d[j + a[i]][1] += d[j][0] * (n - i)
        d[j + a[i]][0] %= mod
        d[j + a[i]][1] %= mod
    if a[i] <= s:
        d[a[i]][0] += i + 1
        d[a[i]][1] += (i + 1) * (n - i)
        d[a[i]][0] %= mod
        d[a[i]][0] %= mod

print(d[s][1])