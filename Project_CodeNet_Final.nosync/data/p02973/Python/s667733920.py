import sys
input = sys.stdin.readline

from collections import deque

import bisect
n = int(input())

a = [int(input()) for i in range(n)]

#color = [a[0]]

d = deque()
d.appendleft(a[0])

for i in range(1,n):
    idx = bisect.bisect_left(d,a[i])
    if idx == 0:
        d.appendleft(a[i])
    else:
        d[idx-1] = a[i]
        
print(len(d))