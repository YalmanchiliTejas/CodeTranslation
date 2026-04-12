import bisect
from collections import deque
n = int(input())
a = [int(input())  for _ in range(n)]
ans = deque([a[0]])
l = 1
for i in range(1,n):
    x = bisect.bisect_left(ans,a[i])
    if (x == 0):
        ans.appendleft(a[i])
        l += 1
    else:
        ans[x-1] = a[i]
print(l)
        