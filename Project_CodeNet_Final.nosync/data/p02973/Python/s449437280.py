n = int(input())
a = []
for _ in range(n):
    a.append(int(input()))

import bisect
from collections import deque
q = deque()
q.append(a[0])

for num in a[1:]:
    if num <= q[0]:
        q.appendleft(num)
    else:
        ind = bisect.bisect_left(q,num)
        ind-=1
        q[ind]=num

print(len(q))