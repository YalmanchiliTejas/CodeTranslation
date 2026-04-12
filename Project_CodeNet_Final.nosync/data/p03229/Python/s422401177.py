n = int(input())
A = sorted([int(input()) for _ in range(n)])

from collections import deque
que = deque(A)

# p1 <= p2 >= p3 <= ...
ans = deque([que.popleft()])
cur = 0
while que:
    if cur % 2 == 0:
        ans.appendleft(que.pop())
        if len(que):
            ans.append(que.pop())
        cur ^= 1
    else:
        ans.appendleft(que.popleft())
        if len(que):
            ans.append(que.popleft())
        cur ^= 1

res1 = 0
for i in range(n - 1):
    res1 += abs(ans[i] - ans[i + 1])

# p1 >= p2 <= p3 >= ...
que = deque(A)
ans = deque([que.pop()])
cur = 1
while que:
    if cur % 2 == 0:
        ans.appendleft(que.pop())
        if len(que):
            ans.append(que.pop())
        cur ^= 1
    else:
        ans.appendleft(que.popleft())
        if len(que):
            ans.append(que.popleft())
        cur ^= 1

res2 = 0
for i in range(n - 1):
    res2 += abs(ans[i] - ans[i + 1])

print(max(res1, res2))