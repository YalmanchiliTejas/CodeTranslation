import numpy as np
n = int(input())
lst = list(map(int,input().split()))
s = 0
t = 0
for x in lst:
  s += x
  t += (x ** 2) % (10**9+7)

w = (s**2-t) % (10**9+7)
if w % 2 == 0:
  print(w//2)
else:
  print((w+10**9+7)//2)
  