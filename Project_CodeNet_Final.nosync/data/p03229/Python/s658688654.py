from collections import deque
import copy
N = int(input())
A = deque(sorted([int(input()) for i in range(N)]))
B = copy.copy(A)
ans = deque([A.popleft()])
while A:
    if A:
        ans.appendleft(A.pop())
    if A:
        ans.append(A.pop())
    if A:
        ans.appendleft(A.popleft())
    if A:
        ans.append(A.popleft())
res_1 = 0
ans = list(ans)
for i in range(N - 1):
    res_1 += abs(ans[i] - ans[i + 1])
ans = deque([B.pop()])
while B:
    if B:
        ans.appendleft(B.popleft())
    if B:
        ans.append(B.popleft())
    if B:
        ans.appendleft(B.pop())
    if B:
        ans.append(B.pop())
res_2 = 0
ans = list(ans)
for i in range(N - 1):
    res_2 += abs(ans[i] - ans[i + 1])
print(max(res_1, res_2))
