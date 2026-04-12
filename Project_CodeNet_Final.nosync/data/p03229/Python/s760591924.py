from collections import deque

N = int(input())
A = [int(input()) for _ in range(N)]

A.sort()

X = deque(A.copy())

B = deque([X.pop()])
flg = True
while X:
    if flg:
        B.append(X.popleft())
        if X:
            B.appendleft(X.popleft())
    else:
        B.append(X.pop())
        if X:
            B.appendleft(X.pop())
    flg = not flg

X = deque(A.copy())
C = deque([X.popleft()])
flg = True
while X:
    if flg:
        C.append(X.pop())
        if X:
            C.appendleft(X.pop())
    else:
        C.append(X.popleft())
        if X:
            C.appendleft(X.popleft())
    flg = not flg

print(max(sum([abs(B[i]-B[i-1]) for i in range(1,N)]), sum([abs(C[i]-C[i-1]) for i in range(1,N)])))