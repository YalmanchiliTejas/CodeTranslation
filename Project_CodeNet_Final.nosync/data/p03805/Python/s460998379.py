n, m = map(int, input().split())
G = [[] for _ in range(n)]

for i in range(m):
    a, b = map(int, input().split())
    a-=1; b-=1
    G[a].append(b)
    G[b].append(a)

flag = (1<<n)-1

def dfs(v=0, visited=1):
    if visited == flag:
        return 1

    cnt = 0
    for to in G[v]:
        if visited & (1<<to):
            continue
        cnt += dfs(to, visited^(1<<to))
    return cnt

print(dfs())