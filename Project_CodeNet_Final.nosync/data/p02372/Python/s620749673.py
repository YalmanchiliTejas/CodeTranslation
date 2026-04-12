from collections import deque
n = input()
G = [[] for i in xrange(n)]
for i in xrange(n-1):
    s, t, w = map(int, raw_input().split())
    G[s].append((t, w))
    G[t].append((s, w))

deq = deque()
def max_dist(dist):
    return dist.items()[dist.values().index(max(dist.values()))]

def bfs(s):
    dist = {s: 0}
    deq.append(s)
    while deq:
        s = deq.popleft()
        for t, w in G[s]:
            if t in dist:
                continue
            dist[t] = dist[s] + w
            deq.append(t)
    return dist

u, co = max_dist(bfs(0))
v, co = max_dist(bfs(u))

dist1 = bfs(u); dist2 = bfs(v)
for i in xrange(n):
    print max(dist1[i], dist2[i])