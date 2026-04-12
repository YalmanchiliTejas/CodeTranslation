# Python3 (3.4.3)
import sys
input = sys.stdin.readline

# -------------------------------------------------------------
# function
# -------------------------------------------------------------


# -------------------------------------------------------------
# main
# -------------------------------------------------------------
N = int(input())
A = [int(input()) for _ in range(N)]

from collections import deque
from bisect import bisect_left

D = deque([])

for a in A:
    i = bisect_left(D,a)
    if i==0:
        D.appendleft(a)
    else:
        D[i-1] = a

print(len(D))