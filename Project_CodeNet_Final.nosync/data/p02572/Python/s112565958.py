n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
f = sum(a)
ans = 0
for i in range(n):
  f = f-a[i]
  ans+= ((f*a[i])%mod)
  ans%=mod
print(ans)