from collections import deque
import bisect

N = int(input())
L = [int(input()) for _ in range(N)]
Q = deque()
Q.append(L[0])

for l in L[1:]:
    r = bisect.bisect_left(Q, l)
    if r == 0:
        Q.appendleft(l)
    else:
        Q[r-1] = l
print(len(Q))
