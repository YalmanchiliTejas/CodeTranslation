n, m = map(int,input().split())
G = [[] for _ in range(n)]
for i in range(m):
    a,b = map(lambda x: int(x)-1,input().split())
    G[a].append(b)
    G[b].append(a)
SAW = [False] * n

def dfs(v,SAW):
    global res
    end = True
    for i in range(n):
        if not SAW[i] and i != v:
            end = False
    if end:
        res += 1
        return
    SAW[v] = True
    for nv in G[v]:
        if SAW[nv]:
            continue
        dfs(nv,SAW)
    SAW[v] = False
res = 0
dfs(0,SAW)
print(res)
