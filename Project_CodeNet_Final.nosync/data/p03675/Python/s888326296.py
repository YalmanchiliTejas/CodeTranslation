from collections import deque

N = int(input())
*A, = map(int, input().split())
B = deque([])
for i, a in enumerate(A):
    if i % 2 == 0:
        B.append(a)
    else:
        B.appendleft(a)
if N % 2 == 1:
    B = list(reversed(B))
print(*B)