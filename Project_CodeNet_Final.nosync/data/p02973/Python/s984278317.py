from collections import deque
import bisect
import sys

input = sys.stdin.readline
N = int(input())
A = [int(input()) for _ in range(N)]
A = A[::-1]

col = [A.pop()]
col = deque(col)

while A:
    a = A.pop()
    if a <= col[0]:
        col.appendleft(a)
    else:
        x = bisect.bisect_left(col, a)
        col[x - 1] = a

ans = len(col)
print(ans)
