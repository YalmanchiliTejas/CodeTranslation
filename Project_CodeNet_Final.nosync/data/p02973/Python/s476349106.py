import bisect
from collections import deque

N = int(input())
a_list = [int(input()) for i in range(N)]

colors = deque([])
colors.append(a_list[0])
for i in range(1, N):
    a = a_list[i]
    idx = bisect.bisect_left(colors, a)
    if idx == 0:
        colors.appendleft(a)
    else:
        colors[idx-1] = a

print(len(colors))