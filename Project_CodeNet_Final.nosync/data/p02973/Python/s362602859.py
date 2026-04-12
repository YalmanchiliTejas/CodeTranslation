n = int(input())
a = [int(input()) for _ in range(n)]

from bisect import bisect

h = []

for ai in a:

    ix = bisect(h, -ai)
    if ix == len(h):
        h.append(-ai)
    else:
        h[ix] = -ai

print(len(h))
