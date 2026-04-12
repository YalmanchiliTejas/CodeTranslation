from bisect import bisect_right
from collections import deque

n = int(input())
a = [int(input()) for _ in range(n)]

c, ans = deque(), 0

for i in range(n):   
    t = bisect_right(c, a[i]-1) - 1
    if t < 0: c.appendleft(a[i])
    else: c[t] = a[i]

print(len(c))
