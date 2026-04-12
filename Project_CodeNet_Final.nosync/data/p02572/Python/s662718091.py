n = int(input())
mod = 10**9+7
f = lambda x: int(x)%mod
a = list(map(f,input().split()))
kei = sum(a[1:])%mod
ans = 0
for i in range(n-1):
  ans += a[i]*(kei)
  ans %= mod
  kei -= a[i+1]
print(ans)