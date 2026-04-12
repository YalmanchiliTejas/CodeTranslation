import sys
import math
import collections
import decimal
import itertools
from collections import deque
from functools import reduce
import heapq
import copy
#import numpy as np
#n = int(input())
n, x, m = map(int, sys.stdin.readline().split())
#s = input()
#a = list(map(int, sys.stdin.readline().split()))


li = [0]*(m+1)
a = []
p = x
a.append(x)
li[x] = 1
for i in range(m):
    p *= p
    p %= m
    if li[p] == 0:
        li[p] = 1
        a.append(p)
    else:
        d = p
        break

b = a.index(d)
bef = sum(a[:b])
afe = sum(a[b:])
loop = len(a) - b
c = n - b

f = c // loop
g = c % loop
rest = sum(a[b:b + g])

ans = bef + afe * f + rest
print(ans)
        
    
    
    


        
