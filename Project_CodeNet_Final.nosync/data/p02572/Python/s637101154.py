n = int(input())
a = list(map(int, input().split()))
s = 0
mod = 10**9+7
asum = 0
for i in a:
    asum += i % mod
for i in range(n-1):
    s += ((a[i]%mod)*(asum-(a[i]%mod)))%mod
    asum = asum-(a[i]%mod)
s %= mod
print(str(s))
