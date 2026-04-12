N, M = list(map(int, input().split(" ")))
path = [tuple(map(int,input().split(" "))) for _ in range(M)]
path += [(item[1], item[0]) for item in path]
visited = [False for _ in range(N)]
visited[0] = True

def dfs(v_, visited):
    if not (False in visited):
        return 1
    ret = 0
    v = v_ + 1 
    for i_ in range(N):
        i = i_ + 1
        if not ((i, v) in path):
            continue
        if visited[i_]:
            continue
        visited[i_] = True
        ret += dfs(i_, visited)
        visited[i_] = False
        
    return ret
print(dfs(0, visited))