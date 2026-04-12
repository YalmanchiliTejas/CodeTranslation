import bisect
import collections

N = int(input())
A = [int(input()) for _ in range(N)]

C = collections.deque()

for a in A:
    p = bisect.bisect_left(C, a)
    if p == 0:
        C.appendleft(a)
    else:
        C[p - 1] = a

print(len(C))
