import bisect
import  collections

N = int(input())
A = [int(input()) for _ in range(N)]

x = collections.deque()

for i, a in enumerate(A):
    if i == 0:
        x.append(a)
    else:
        r = bisect.bisect_left(x, a)
        if r == 0:
            x.appendleft(a)
        else:
            x[r - 1] = a

print(len(x))
