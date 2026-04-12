from bisect import bisect_left
from collections import deque

n = int(input())
a = [int(input()) for _ in range(n)]

q = deque([-1])
for x in a:
    insert_pos = bisect_left(q, x) - 1
    # bisect_left[0,len(lis)] == 以上の最小
    # 手前は未満の最大[-1,len(lis))
    if insert_pos == -1:
        q.appendleft(x)
    else:
        q[insert_pos] = x

ret = len(q)

print(ret)

# 最小パス被覆
