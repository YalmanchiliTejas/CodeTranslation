N = int(input())
A = [int(input()) for i in range(N)]

from bisect import *

h = []

for a in A:
    x = bisect_right(h, -a)
    if len(h) <= x:
        h.append(-a)
    else:
        h[x] = -a

result = len(h)

print(result)

