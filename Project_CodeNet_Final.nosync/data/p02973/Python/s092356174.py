import bisect
from collections import deque

N = int(input())
a = []
for _ in range(N):
  a.append(int(input()))

d = deque()
d.append(a[-1])
for i in reversed(range(N-1)):
	if a[i] >= d[-1]:
		d.append(a[i])
	else:
		index = bisect.bisect_right(d,a[i])
		d[index] = a[i]

print(len(d))
