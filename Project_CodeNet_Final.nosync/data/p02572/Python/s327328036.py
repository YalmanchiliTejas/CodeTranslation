n = int(input())
a = list(map(int,input().split()))
s = sum(a[1:])
ans = 0
mod = 10**9+7
for i in range(n):
  if i != 0:
    s -= a[i]
  ans += (a[i]*s)%mod
  ans %= mod
print(ans)