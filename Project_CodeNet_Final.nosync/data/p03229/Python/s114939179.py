from collections import deque
N = int(input())
a = []
for i in range(N):
    a.append(int(input()))
a.sort()
d = deque(a)
ans = deque([d.popleft()])
cur = 0
while d:
    if cur%2 == 0:
        ans.appendleft(d.pop())
        if len(d) != 0:
            ans.append(d.pop())
        cur += 1
    else:
        ans.appendleft(d.popleft())
        if len(d) != 0:
            ans.append(d.popleft())
        cur += 1
p = 0
for x, y in zip(list(ans), list(ans)[1:]):
    p += abs(x-y)

d = deque(a)
ans = deque([d.pop()])
cur = 1
while d:
    if cur%2 == 0:
        ans.appendleft(d.pop())
        if len(d) != 0:
            ans.append(d.pop())
        cur += 1
    else:
        ans.appendleft(d.popleft())
        if len(d) != 0:
            ans.append(d.popleft())
        cur += 1
q = 0
for x, y in zip(list(ans), list(ans)[1:]):
    q += abs(x-y)
print(max(p, q))