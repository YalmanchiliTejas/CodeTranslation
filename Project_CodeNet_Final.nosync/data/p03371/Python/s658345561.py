import sys
import math
ans = float('inf')
a,b,c,x,y = map(int,sys.stdin.readline().rstrip().split())
for i in range(max(x,y)+1):
  if x > y and i >= y:
  	sum = a * (x - i) +  2 * i * c
  elif y > x and i >= x:
    sum = b * (y - i) + 2 * i * c
  else:
    sum = a * (x - i) + b * (y - i) + 2 * i * c
  ans = min(ans,sum)
print(ans)