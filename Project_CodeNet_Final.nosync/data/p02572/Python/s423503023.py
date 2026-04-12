n = int(input())
mod = 1000000007
a = [int(i)%mod for i in input().split()]
s = [0]*(n+1)
for i in range(n)[::-1]:
    s[i] = (s[i+1] + a[i])%mod
ans = 0
for i in range(n-1):
    ans += s[i+1]*a[i]%mod
    ans %= mod
print(ans)