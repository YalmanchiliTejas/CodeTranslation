n = int(input())
a = list(map(int,input().split()))
ans = 0
mod = 10**9+7
s = sum(a)
for i in range(n):
    ans = (ans + s*a[i] - a[i]**2) % mod
print(ans*pow(2,mod-2,mod)%mod)