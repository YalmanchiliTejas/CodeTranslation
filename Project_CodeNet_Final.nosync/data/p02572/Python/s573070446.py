n = int(input())
a = list(map(int,input().split()))

par = [0] * n
par[0] = a[0]

mod = 10**9 + 7

for i in range(1,n):
  par[i] = par[i-1] + a[i]
  par[i] = par[i] % mod
  
ans = 0
#print(par)

for i in range(n-1):
  ans += a[i] * (par[-1] - par[i])
  ans = ans % mod
  
print(ans%mod)