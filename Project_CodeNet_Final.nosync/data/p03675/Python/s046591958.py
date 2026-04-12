from collections import deque

n = int(input())
a = [ int(x) for x in input().split() ]

q = deque([])
for key, value in enumerate(a):
    if key & 1 == n & 1:
        q.append(value)
    else:
        q.appendleft(value)

print(*q)