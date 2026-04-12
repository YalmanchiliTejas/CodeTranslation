from collections import deque


n = int(input())
info = [list(map(int, input().split())) for i in range(n - 1)]

tree = [[] for i in range(n)]
for a, b in info:
    a -= 1
    b -= 1
    tree[a].append(b)
    tree[b].append(a)
    
root = 0
par = {root: -1}
q = deque([root])
topo = []
while q:
    v = q.popleft()
    topo.append(v)
    for nxt_v in tree[v]:
        if nxt_v in par:
            continue
        par[nxt_v] = v
        q.append(nxt_v)

used = [False] * n
for v in topo[::-1]:
    if used[v]:
        continue
    else:
        used[v] = True
        if par[v] == -1:
            print("First")
            exit()
        if used[par[v]]:
            print("First")
            exit()
        used[par[v]] = True
print("Second")