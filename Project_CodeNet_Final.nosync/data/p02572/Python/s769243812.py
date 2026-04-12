n = int(input())
mod = 1000000007
a = [int(i) for i in input().split()]
s = 0
for i in range(n):
    s += a[i]%mod
    s %= mod
ans = 0
for i in range(n-1):
    s -= a[i]
    s %= mod
    ans += a[i]*s%mod
    ans %= mod    
print(ans)