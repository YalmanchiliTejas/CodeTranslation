from collections import deque
from bisect import bisect_left
inf = float('inf')


N = int(input())
A = [int(input()) for _ in range(N)]

color = deque()

for a in A:
    pos = bisect_left(color, a)
    if pos == 0:
        color.appendleft(a)
    else:
        color[pos-1] = a

ans = len(color)
print(ans)