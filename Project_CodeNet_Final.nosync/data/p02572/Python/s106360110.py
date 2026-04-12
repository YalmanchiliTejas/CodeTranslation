n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7

cur = 0
res = 0
for i in range(n-1):
    cur = (cur + a[n-1-i]) % mod
    tmp = (a[n-2-i] * cur) % mod
    res = (res + tmp) % mod

print(res)