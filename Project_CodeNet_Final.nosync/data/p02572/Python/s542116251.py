n=int(input())
l=list(map(int, input().split()))
ans=sum(l)**2

sq=0
for i in range(n):
  sq+=l[i]**2
ans=(ans-sq)//2

import numpy as np
print(np.mod(ans, 10**9+7))