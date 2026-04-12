from sys import stdin
import bisect
from collections import deque

N = int(stdin.readline().rstrip())
A = [int(stdin.readline().rstrip()) for _ in range(N)]

colors = deque([10 ** 10])
for i in range(N):
    bi = bisect.bisect_left(colors, A[i])
    bir = bisect.bisect_right(colors, A[i])
    if bir == len(A):
        colors[len(A) - 1] = A[i]
    elif bi == 0:
        colors.appendleft(A[i])
    else:
        colors[bi - 1] = A[i]

print(len(colors) - 1)
