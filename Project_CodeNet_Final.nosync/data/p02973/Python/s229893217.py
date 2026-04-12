import bisect
from collections import deque
N = int(input())
ans = deque()

for _ in range(N):
    a = int(input())
    ind = bisect.bisect_left(ans, a)
    if ind == 0:
        ans.appendleft(a)
    else:
        ans[ind-1] = a
print(len(ans))
