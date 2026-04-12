n = int(input())
a = list(map(int,input().split()))
sa = sum(a)
t = 0
m = 10**9 + 7
for i in range(n-1):
  sa -= a[i]
  t += a[i]*sa
  t = t%m
print(t)
  
