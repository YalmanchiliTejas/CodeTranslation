from bisect import bisect_left, bisect_right
from collections import deque
import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
infi = 10 ** 20

# 長さがi+1のときの最長部分増加列の末尾の最小値。
n, *A = map(int, read().split())
LIS = deque([10 ** 10])
for a in A:
    a *= -1
    pos1 = bisect_left(LIS, a)
    pos2 = bisect_right(LIS, a)
    if LIS[-1] <= a:
        LIS.append(a)
    else:
        if LIS[pos1] == a:
            LIS[pos2] = a
        else:
            LIS[pos1] = a

print(len(LIS))
