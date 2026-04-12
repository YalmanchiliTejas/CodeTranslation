n,m = map(int, raw_input().split())
adj = [[] for i in range(n)]

for i in range(m):
    a,b = map(int, raw_input().split())
    a -= 1
    b -= 1
    adj[a].append(b)
    adj[b].append(a)


q = [(0,0)]
all_visited = (1 << n) - 1
ans = 0

while len(q) > 0:
    u,visited = q.pop(0)
    visited = visited ^ (1 << u)
    
    if visited == all_visited:
       ans += 1 
    
    for v in adj[u]:
        if visited & (1 << v):
            continue
        q.append((v,visited))

print ans        