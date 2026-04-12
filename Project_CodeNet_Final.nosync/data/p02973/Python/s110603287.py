from bisect import bisect_left
from collections import deque

n = int(input())
max_color = deque([int(input())])
for _ in range(n-1):
  a = int(input())
  if a <= max_color[0]:
    max_color.appendleft(a)
  else:
    index = bisect_left(max_color, a) - 1
    max_color[index] = a
print(len(max_color))