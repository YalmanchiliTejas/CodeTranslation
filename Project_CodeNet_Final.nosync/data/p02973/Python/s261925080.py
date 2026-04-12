from collections import deque
import bisect

N = int(input())
A = [int(input()) for _ in range(N)]

colors = deque([A[0]])
for a in A[1:]:
    i = bisect.bisect_left(colors, a)
    if i != 0:
        colors[i - 1] = a
    else:
        colors.appendleft(a)

print(len(colors))
