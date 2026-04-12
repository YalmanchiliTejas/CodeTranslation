import math
import numpy as np
import queue
from collections import deque
import heapq

def cmb(n,r):
    c = 1
    for i in range(r):
        c *= (n-i)
    for i in range(r):
        c //= (i+1)
    return c

n = input()
k = int(input())
ln = len(n)
ans = 0

nn0 = 0
for i in range(ln):
    if int(n[i]) > 0:
        ans += cmb(ln-i-1,k-nn0)*(9**(k-nn0))
        nn0 += 1
        ans += (int(n[i])-1)*cmb(ln-i-1,k-nn0)*(9**(k-nn0))
    if nn0 == k:
        ans += 1
        break

print(ans)
