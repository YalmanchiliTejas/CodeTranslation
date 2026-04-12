from collections import deque

n = int(input())
A = list(map(int, input().split()))

d = deque()

for i, a in enumerate(A):
    if i%2 == 0:
        d.append(a)
    else:
        d.appendleft(a)

if n%2==0:
    print(*d)
else:
    d = list(d)
    print(*d[::-1])
