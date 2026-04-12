from collections import defaultdict, deque

N, M = map(int, input().split())
AB = [tuple(map(int, input().split())) for _ in range(M)]

D = defaultdict(set)
for a, b in AB:
    D[a].add(b)
    D[b].add(a)

ans = 0
queue = deque([(1, {1})])
while queue:
    q = queue.popleft()
    for x in D[q[0]] - q[1]:
        s = q[1] | {x}
        if len(s) == N:
            ans += 1
        else:
            queue.append((x, s))
print(ans)
