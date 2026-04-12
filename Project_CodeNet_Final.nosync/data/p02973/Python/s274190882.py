N = int(input())
seq = [int(input()) for _ in range(N)]
from collections import deque
import bisect
LIS = deque([seq[0]])
for i in range(1,len(seq)):
    if seq[i] <= LIS[0]:
        LIS.appendleft(seq[i])
    else:
        LIS[bisect.bisect_left(LIS, seq[i])-1] = seq[i]

print(len(LIS))
