n = int(input())
a = list(map(int, input().split()))
mod = 10**9 + 7
s = [0] * n
ss = 0
for i in range(n):
  ss += a[i]%mod
  s[i] = ss

s.reverse()
ans = 0
for i in range(n-1):
  #print (a[n-1-i],s[i+1])
  ans += a[n-1-i] *s[i+1]
  ans %= mod
print (ans)