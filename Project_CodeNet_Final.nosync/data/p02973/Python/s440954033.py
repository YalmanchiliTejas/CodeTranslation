import sys
from bisect import bisect_left, bisect_right
from collections import deque




n = int(sys.stdin.readline())
L = [int(sys.stdin.readline()) for i in range(n)]
IS = deque([L[0]])
for i in range(1, n):
    if L[i] <= IS[0]:
        IS.appendleft(L[i])
    else:
        IS[bisect_left(IS, L[i]) - 1] = L[i]



print(len(IS))