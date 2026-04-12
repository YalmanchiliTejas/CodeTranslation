N = int(input())
A = [int(input()) for i in range(N)]
from bisect import bisect

arr = []
for a in A:
    i = bisect(arr, -a)
    if i==len(arr):
        arr.append(-a)
    else:
        arr[i] = -a
print(len(arr))