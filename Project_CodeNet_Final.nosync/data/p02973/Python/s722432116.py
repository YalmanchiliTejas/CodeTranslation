from bisect import bisect_left, bisect_right

def LIS(arr):  #bisect.bisect_left
    n = len(arr)
    lis = [arr[0]]
    for a in arr:
        if a > lis[-1]:
            lis.append(a)
        else:
            lis[bisect_left(lis, a)] = a
    return len(lis)

import sys
input = sys.stdin.readline

N = int(input())

A = []
for i in range(N):
    A.append((-int(input()), i))

print(LIS(A))
