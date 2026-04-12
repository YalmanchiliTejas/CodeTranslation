from collections import deque
import bisect

n = int(input())
a = [int(input()) for _ in range(n)]


b = deque([])

for ai in a:
    if len(b) == 0:
        b.append(ai)
    else:
        if ai <= b[0]:
            b.appendleft(ai)
        else:
            index = bisect.bisect_left(b, ai)
            b[index-1] = ai

print(len(b))
