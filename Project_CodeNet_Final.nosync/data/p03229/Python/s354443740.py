from collections import deque
import copy

N = int(input())
a = [int(input()) for i in range(N)]
a.sort()
b = copy.copy(a)

A = deque(a)

r = A[0]
l = A.popleft()

ans = 0
while True:
    if len(A) == 0:
        break
    c = A.pop()
    ans += abs(l-c)
    l = c
    if len(A) == 0:
        break
    c = A.pop()
    ans += abs(r-c)
    r = c
    if len(A) == 0:
        break
    c = A.popleft()
    ans += abs(l-c)
    l = c
    if len(A) == 0:
        break
    c = A.popleft()
    ans += abs(r-c)
    r = c

B = deque(b)
r = B[-1]
l = B.pop()
ans2 = 0
while True:
    if len(B) == 0:
        break
    c = B.popleft()
    ans2 += abs(l-c)
    l = c
    if len(B) == 0:
        break
    c = B.popleft()
    ans2 += abs(r-c)
    r = c
    if len(B) == 0:
        break
    c = B.pop()
    ans2 += abs(l-c)
    l = c
    if len(B) == 0:
        break
    c = B.pop()
    ans2 += abs(r-c)
    r = c
print(max(ans,ans2))
