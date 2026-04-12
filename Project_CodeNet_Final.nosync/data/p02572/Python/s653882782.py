n = int(input())
a = list(map(int,input().split()))
mod = 10**9+7
s = 0
t = 0
for i in range(n):
  ai = a[i]
  s = (s+ai)%mod
  t = (t+ai**2)%mod
s = (s*s)%mod
x = (s -t)%mod
if x%2 == 0:
  print(x//2)
else:
  print((x+mod)//2)
  
             