from collections import deque
n = int(input())
A = list(map(int,input().split()))

b = deque()
for i,a in enumerate(A):
    if i % 2 == 0:
        b.append(a)
    elif i % 2 == 1:
        b.appendleft(a)

if n % 2 == 1:
    b.reverse()
print(*b)