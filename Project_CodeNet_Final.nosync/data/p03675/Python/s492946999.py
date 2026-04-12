from collections import deque
n = int(input())
a = [int(i) for i in input().split()]
b = deque()
f = True
for i in range(n):
    if f: b.append(a[i])
    else: b.appendleft(a[i])
    f = not f
if i % 2 == 0: b.reverse()
print(*b)
