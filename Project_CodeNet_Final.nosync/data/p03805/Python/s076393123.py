N, M = map(int, input().split())
ab = []
for _ in range(M):
    ab.append(tuple(map(int, input().split())))

G = [[] for _ in range(N + 1)]
for el in ab:
    a, b = el
    G[a].append(b)
    G[b].append(a)

#print(G)
cnt = 0
seen=[False] * (N + 1)
def dfs(parent):
    global cnt
    seen[parent] = True
    if seen.count(True) == N:
        cnt += 1
    for child in G[parent]:
        if seen[child] == False:
            dfs(child)
            seen[child] = False
dfs(1)
print(cnt)

