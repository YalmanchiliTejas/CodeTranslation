import bisect
from collections import deque
N = int(input())

arr = deque([int(input())])
for _ in range(N-1):
    a = int(input())
    x = bisect.bisect_left(arr, a)
    if x == 0:
        arr.appendleft(a)
    else:
        arr[x-1] = a


print(len(arr))
