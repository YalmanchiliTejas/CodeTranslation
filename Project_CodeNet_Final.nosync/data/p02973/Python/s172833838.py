import bisect
from collections import deque

N = int(input())
A = []
for i in range(N):
    A.append(int(input()))

ans = deque([A[0]])
for i in range(1, N):
    index = bisect.bisect_left(ans, A[i])
    if index > 0:
        ans[index - 1] = A[i]
    else:
        ans.appendleft(A[i])

print(len(ans))
