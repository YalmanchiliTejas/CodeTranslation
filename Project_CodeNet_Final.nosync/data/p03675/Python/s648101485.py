from collections import deque

n = int(input())
A = list(map(int,input().split()))

dq = deque()
for i in range(n):
    if i % 2 == 0:
        dq.append(A[i])
    else:
        dq.appendleft(A[i])

ans = list(dq)
if n % 2 == 1:
    ans.reverse()
print(*ans)