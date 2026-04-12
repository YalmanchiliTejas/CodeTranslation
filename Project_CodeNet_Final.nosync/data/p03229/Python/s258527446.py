from collections import deque
N = int(input())
A = deque(sorted([int(input()) for _ in range(N)]))
B = deque([])
B.append(A.popleft())
cnt = 0
while A:
    a0 = A[0]
    a1 = A[-1]
    b0 = B[0]
    b1 = B[-1]
    c00 = abs(a0-b0)
    c01 = abs(a0-b1)
    c10 = abs(a1-b0)
    c11 = abs(a1-b1)
    cmax = max(c00,c01,c10,c11)
    if cmax == c00:
        B.appendleft(A.popleft())
    elif cmax == c01:
        B.append(A.popleft())
    elif cmax == c10:
        B.appendleft(A.pop())
    else:
        B.append(A.pop())
    cnt += cmax
print(cnt)