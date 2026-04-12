from collections import deque
N = int(input())
A = [int(input()) for _ in range(N)]

A.sort()
q = deque([A[0]])
i = 1
j = N-1
while i <= j:
    temp = max(abs(A[i]-q[0]), abs(A[j]-q[0]), abs(A[i]-q[-1]), abs(A[j]-q[-1]))
    if temp == abs(A[i]-q[0]):
        q.appendleft(A[i])
        i += 1
    elif temp == abs(A[j]-q[0]):
        q.appendleft(A[j])
        j -= 1
    elif temp == abs(A[i]-q[-1]):
        q.append(A[i])
        i += 1
    else:
        q.append(A[j])
        j -= 1
L = list(q)
ans = 0
for i in range(N-1):
    ans += abs(L[i+1]-L[i])
print(ans)