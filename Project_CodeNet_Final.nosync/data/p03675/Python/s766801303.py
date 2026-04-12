from collections import deque

n = int(input())
a = list(map(int, input().strip().split()))
b = deque()

for i in range(n):
    if i % 2:
        b.appendleft(a[i])
    else:
        b.append(a[i])
else:
    if i % 2 == 0:
        b.reverse()

print(" ".join(list(map(str, b))))