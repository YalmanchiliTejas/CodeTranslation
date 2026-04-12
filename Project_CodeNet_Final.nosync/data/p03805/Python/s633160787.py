from collections import deque

N, M = map(int, input().split())
to = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    to[a - 1].append(b - 1)
    to[b - 1].append(a - 1)

q = deque()
q.append((0, set(), -1))
ans = 0
while len(q):
    a, s, p = q.pop()
    s.add(a)
    if len(s) == N:
        ans += 1
        continue
    for b in to[a]:
        if b not in s:
            q.append((b, s | {b}, a))
print(ans)
