import bisect
from collections import deque

N = int(input())

# c = [int(input())]
c = deque()
c.appendleft(int(input()))


for ai in range(1, N):
    a = int(input())
    if a <= c[0]:
        c.appendleft(a)
    else:
        i = bisect.bisect_left(c, a) - 1
        c[i] = a

print(len(c))
