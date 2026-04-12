import bisect
from collections import deque

n = int(input())
a = []
for i in range(n):
    a.append(int(input()))


def colorfind(a, colors):
    index = bisect.bisect_left(colors, a)
    return index


color = deque([])
for i in range(n):
    if i == 0:
        color.appendleft(a[i])
    elif color[0] >= a[i]:
        color.appendleft(a[i])
    else:
        colorindex = colorfind(a[i], color)
        color[colorindex - 1] = a[i]

print(len(color))

