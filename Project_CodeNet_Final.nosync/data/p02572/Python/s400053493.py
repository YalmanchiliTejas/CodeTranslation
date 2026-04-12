from sys import setrecursionlimit
from collections import Counter
from collections import defaultdict
from collections import deque
from heapq import heapify
from heapq import heappop
from heapq import heappush
from time import time
import re
setrecursionlimit(10**9)
mod=10**9+7
inf=10**18

n=int(input())
a=[int(x) for x in input().split()]
cum_a=[]
for i in range(n):
    if i==0:cum_a.append(a[i])
    else:cum_a.append(cum_a[-1]+a[i])
ans=0
for i in range(n-1):
    ans+=a[i]*(cum_a[n-1]-cum_a[i])
    ans%=mod
     
print(ans)