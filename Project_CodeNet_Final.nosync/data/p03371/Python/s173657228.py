

import math
def solve():
  a,b,c,x,y = (int(i) for i in input().split())
  ans = 10**15
  for ab in range(max(x,y)+15):
    cost = 0
    buyab = ab*2
    cost += buyab*c
    cost += a*max(x-ab,0) + b*max(y-ab,0)
    
    ans = min(cost,ans)
  print(ans)
solve()