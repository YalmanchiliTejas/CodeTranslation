import bisect
from collections import deque

N = int(input())

ans = deque([-1])
for _ in range(N):
    a = int(input())
    i = bisect.bisect_left(ans, a)
    if i == 0:
        ans.appendleft(a)
    else:
        ans[i-1] = a
print(len(ans))
