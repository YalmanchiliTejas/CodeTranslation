N = int(input())
A = []
for _ in range(N):
    A.append(int(input()))

from collections import deque
from typing import Deque

A.sort()

DL = Deque(A)
DS = Deque(A)

LL = [0 for _ in range(N)]
LS = [0 for _ in range(N)]


if N % 2 == 0:

    for i in range(1, N, 2):
        LS[i] = DS.popleft()
        LL[i] = DL.pop()
    for j in range(0, N, 2):
        LS[j] = DS.popleft()
        LL[j] = DL.pop()

else:
    for i in range(1, N):
        if i % 2 == 1:
            LS[i] = DS.pop()
            LL[i] = DL.popleft()
        else:
            LS[i] = DS.popleft()
            LL[i] = DL.pop()

    LS[0] = DS.pop()
    LL[0] = DL.pop()

ansS = 0
ansL = 0
for i in range(1, N, 2):
    if i == N - 1:
        ansS += abs(LS[i] - LS[i-1])
        ansL += abs(LL[i] - LL[i-1])
    else:
        ansS += abs(LS[i] - LS[i-1])
        ansS += abs(LS[i] - LS[i+1])

        ansL += abs(LL[i] - LL[i-1])
        ansL += abs(LL[i] - LL[i+1])

print(max(ansS, ansL))
