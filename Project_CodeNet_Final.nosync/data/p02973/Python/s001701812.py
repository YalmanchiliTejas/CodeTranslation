import bisect
from collections import deque


n = int(input())
lines = deque()
for _ in range(n):
    a = int(input())

    index = bisect.bisect_left(lines, a)
    if index == 0:
        lines.appendleft(a)
        continue
    
    lines[index - 1] = a

print(len(lines))
