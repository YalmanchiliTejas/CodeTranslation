from collections import deque
import bisect

N = int(input())
A = [int(input()) for i in range(N)]

colors = deque()
for i in range(N):
    index = bisect.bisect_left(colors, A[i])
    if index == 0:
        colors.appendleft(A[i])
    else:
        colors[index - 1] = A[i]
print(len(colors))
