import sys
#import numpy as np
import math
import itertools
#from fractions import Fraction
#import itertools
#from collections import deque
#import heapq
#from fractions  import gcd
#input=sys.stdin.readline
n,m=map(int,input().split())
v=tuple(tuple(map(lambda x: int(x)-1,input().split())) for _ in range(m))

node=[[] for _ in range(n)]
for pair in v:
    node[pair[0]].append(pair[1])
    node[pair[1]].append(pair[0])
c=0
p=list(itertools.permutations(list(range(1,n))))
for res in p:
    for i in range(n-1):
        if i==0:
          if res[0] in node[0]:
            continue
          else:
            break
        if res[i] in node[res[i-1]]:
            continue
        else:
            break
    else:
        c+=1
print(c)