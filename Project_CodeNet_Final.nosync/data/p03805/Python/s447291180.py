N, M = map(int, input().split())
adj = dict((i+1, []) for i in range(N))

for i in range(M):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)
queue = [(1,)]
ans = 0
while queue:
    q = queue.pop()

    if len(q) == N:
        ans+=1
        continue
    now = q[-1]

    for nextp in adj[now]:
        if not nextp in q:
            queue.append(q+(nextp,))
print(ans)