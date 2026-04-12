from bisect import bisect_left
from collections import deque
n = int(input())
a = [int(input()) for _ in range(n)]

LIS = deque()  # LISの中身は、LISの最小の数字を保持する
LIS.append(a[0])
for i in range(1, n):
    idx = bisect_left(LIS, a[i])
    if idx == 0:
        LIS.appendleft(a[i])
    else:
        LIS[idx-1] = a[i]
print(len(LIS))