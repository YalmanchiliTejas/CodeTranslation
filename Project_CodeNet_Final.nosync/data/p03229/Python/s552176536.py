from sys import stdin
from collections import deque

N = int(stdin.readline())
A = sorted([int(stdin.readline()) for i in range(N)])
ans1 = deque([A[N-1]])
ans2 = deque([A[0]])

f = 0
f2 = 1
b = N - 2
b2 = N - 1
s = True
while f <= b:
    if s:
        ans1.append(A[f])
        f += 1
        if f <= b:
            ans1.appendleft(A[f])
            f += 1
        ans2.append(A[b2])
        b2 -= 1
        if f2 <= b2:
            ans2.appendleft(A[b2])
            b2 -= 1
    else:
        ans1.append(A[b])
        b -= 1
        if f <= b:
            ans1.appendleft(A[b])
            b -= 1
        ans2.append(A[f2])
        f2 += 1
        if f2 <= b2:
            ans2.appendleft(A[f2])
            f2 += 1
    s = not s

a1 = a2 = 0
ans1 = list(ans1)
ans2 = list(ans2)
for i in range(N-1):
    a1 += abs(ans1[i] - ans1[i+1])
    a2 += abs(ans2[i] - ans2[i+1])

print(max(a1, a2))