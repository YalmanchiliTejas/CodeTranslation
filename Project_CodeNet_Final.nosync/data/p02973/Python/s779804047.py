from collections import deque
from bisect import bisect_left
n = int(input())
a = [int(input()) for _ in range(n)]
ans = deque([a[0]])
for a_i in a[1:]:
    if ans[0] < a_i:
        i = bisect_left(ans, a_i)
        ans[i-1] = a_i
    else:
        ans.appendleft(a_i)

print(len(ans))


