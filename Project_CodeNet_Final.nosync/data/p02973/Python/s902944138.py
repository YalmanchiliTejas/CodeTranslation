from collections import deque
from bisect import bisect_left

n = int(input())
arr = deque()

for _ in range(n):
    i = int(input())
    if not arr:
        arr.append(i)
        continue

    if i <= arr[0]:
        arr.appendleft(i)
        continue

    idx = bisect_left(arr, i)
    arr[idx - 1] = i

    while idx < len(arr) and arr[idx - 1] > arr[idx]:
        arr[idx - 1], arr[idx] = arr[idx], arr[idx - 1]
        idx += 1

print(len(arr))
