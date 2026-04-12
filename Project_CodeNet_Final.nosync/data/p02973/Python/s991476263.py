# 狭義単調増加部分列
import bisect
from collections import deque

n = int(input())
A = [int(input()) for _ in range(n)]
que = deque()

for i in range(n):
    if len(que) == 0:
        deque.appendleft(que, A[i])
    else:
        idx = bisect.bisect_left(que, A[i])
        if idx == 0:
            deque.appendleft(que, A[i])
        else:
            que[idx - 1] = A[i]

ans = len(que)
print(ans)
