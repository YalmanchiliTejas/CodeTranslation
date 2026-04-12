from bisect import bisect_left
from collections import deque

N = int(input())
As = [int(input()) for _ in range(N)]

list_ = deque([As[0]])
for a in As[1:]:
    i = bisect_left(list_, a) - 1
    if i < 0:
        list_.appendleft(a)
    else:
        list_[i] = a
print(len(list_))