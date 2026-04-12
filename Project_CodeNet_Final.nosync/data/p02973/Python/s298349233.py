n = int(input())
a = []
for i in range(n):
  a.append(int(input()))
from collections import deque
import bisect

color = deque([a.pop(0)])
color_count =0 
for ai in a: 
    index = bisect.bisect_left(color, ai)
    if index > 0:
        color[index -1] = ai
    else:
        color.appendleft(ai)
print(len(color))