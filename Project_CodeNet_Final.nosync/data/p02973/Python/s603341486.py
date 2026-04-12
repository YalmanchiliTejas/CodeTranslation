import bisect
from collections import deque
n = int(input())
color = [-1]*n

for i in range(n):
    a = int(input())
    color[bisect.bisect_left(color,a) - 1] = a

ans = n - bisect.bisect_right(color,-1)
print(ans)
