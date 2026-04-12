N, M = map(int, input().split())
es = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    es[a-1].append(b-1)
    es[b-1].append(a-1)

def dfs(v, used):
    global cnt
    used[v] = 1
    if all(used):
        cnt+=1
    for nv in es[v]:
        if used[nv]:
            continue
        dfs(nv, used)
    used[v] = 0


used = [0] * N
cnt = 0
dfs(0, used)
print(cnt)