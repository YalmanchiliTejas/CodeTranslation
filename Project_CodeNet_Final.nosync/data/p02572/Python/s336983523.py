n = int(input())
a = list(map(int, input().split()))
s = [0]*n
ss = 0
mod = 10**9+7
for i in range(n):
  ss += a[i]
  s[i] = ss
a.reverse()
ans = 0
for i in range(n-1):
  ans += (a[i]*s[n-2-i])%mod
print (ans%mod)