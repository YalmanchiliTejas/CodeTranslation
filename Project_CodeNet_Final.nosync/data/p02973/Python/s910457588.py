import sys, math
from collections import deque

readline = sys.stdin.readline

N = int(readline())
A = [int(readline()) for i in range(N)]


heads = []

for a in A:
    if len(heads) == 0:
        heads.append(a)
    else:
        left = 0
        right = len(heads) - 1
        while right - 1 > left:
            mid = (left + right) // 2
            if a <= heads[mid]:
                left = mid + 1
            else:
                right = mid

        if a > heads[left]:
            heads[left] = a
        elif a > heads[right]:
            heads[right] = a
        else:
            heads.append(a)

print(len(heads))
    