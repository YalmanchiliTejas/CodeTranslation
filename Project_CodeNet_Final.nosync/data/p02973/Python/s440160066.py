import bisect
from collections import deque
n = int(input())
color = deque([int(input())])
for i in range(1,n):
    num = int(input())
    if color[0] >= num:
        color.appendleft(num)
    else:
        bis = bisect.bisect_left(color, num)
        color[bis-1] = num
print(len(color))
