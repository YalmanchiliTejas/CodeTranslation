N, M = [int(x) for x in input().split()]
G = [[] for x in range(N)]
V = (1 << N) - 1
count = 0

for i in range(M):
    a, b = [int(x) for x in input().split()]
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)


def dfs(s, v):
    global count
    if v == V:
        count += 1
    for t in G[s]:
        if (v >> t & 1) == 0:
            dfs(t, v | 1 << t)


dfs(0, 1)

print(count)