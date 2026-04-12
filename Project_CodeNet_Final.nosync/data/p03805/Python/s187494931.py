from collections import defaultdict
# dfs, check path len, count paths                                                                                                                           
# test = 2                                                                                                                                                   
n, m = map(int, input().split())
edges = [map(int, input().split()) for i in range(m)]
graph = defaultdict(list)
for k,v in edges:
    graph[k].append(v)
    graph[v].append(k)

cnt = 0
# dfs                                                                                                                                                        
def dfs(node, visited):
    global cnt
    if node in visited:
        return None
    elif len(visited) + 1 == n:
        cnt += 1
        return None
    else:
        for v in graph[node]:
            dfs(v, visited+[node])
dfs(1, [])
print(cnt)