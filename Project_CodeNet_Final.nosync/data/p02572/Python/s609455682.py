n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7

res = 0
s = 0
for i in range(1, len(a)):
    s = (s+a[i-1])%mod
    res = (res+(s*a[i])%mod)%mod

print(res)