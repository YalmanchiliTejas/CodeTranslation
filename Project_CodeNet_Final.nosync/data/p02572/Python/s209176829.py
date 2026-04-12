n = int(input())
a = [int(i) for i in input().split()]
s = [0 for i in range(n)]

s[-2] = a[n-1]
for i in range(3, n+1):
  s[-i] = s[-(i-1)] + a[-(i-1)]
  
ans = 0
for i in range(n):
  ans += a[i] * s[i]
  
print(ans % ((10**9)+7))
