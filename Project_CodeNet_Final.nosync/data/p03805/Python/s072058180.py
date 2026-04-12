import itertools


N, M = map(int, input().split())
path = [ list(map(int, input().split())) for _ in range(M)]

graph = [[] for _ in range(N)]
for p in path:
    graph[p[0]-1].append(p[1]-1)
    graph[p[1]-1].append(p[0]-1)
# print(graph)

arr = [i for i in range(1,N)]
perms = [v for v in  itertools.permutations(arr, len(arr))]
# print(perms)

solved = 0
for perm in perms:
    now = 0
    res = True

    for v in perm:
        if v in graph[now]:
            now = v
        else:
            res = False
            break
    if res:
        solved += 1

print(solved)
    
    