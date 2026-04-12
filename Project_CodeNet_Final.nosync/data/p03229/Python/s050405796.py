from collections import deque
n = int(input())
A = sorted(int(input())for _ in range(n))
L = 1
R = n-1
B = deque([A[0]])
prev_L = A[0]
prev_R = A[0]
while L <= R:
    x, y = A[L], A[R]
    if abs(min(prev_L, prev_R)-y) < abs(max(prev_L, prev_R)-x):
        if prev_L < prev_R:
            B.append(x)
            prev_R = x
        else:
            B.appendleft(x)
            prev_L = x
        L += 1
    else:
        if prev_L < prev_R:
            B.appendleft(y)
            prev_L = y
        else:
            B.append(y)
            prev_R = y
        R -= 1

B = list(B)
ans = 0
for x, y in zip(B, B[1:]):
    ans += abs(x-y)
print(ans)