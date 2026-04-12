# -*- coding: utf-8 -*-

line = input().split(" ")
n = int(line[0])
m = int(line[1])
edge = [[] for _ in range(n+1)]

for _ in range(m):
    line = input().split(" ")
    a = int(line[0])
    b = int(line[1])

    edge[a].append(b)
    edge[b].append(a)


visited = [False for _ in range(n+1)]
visited[0] = True#dummy
visited[1] = True

def solve(x):
    allVisited = True
    for e in visited:
        allVisited = allVisited and e
    if allVisited:
        return 1

    ret = 0
    for e in edge[x]:
        if not visited[e]:
            visited[e] = True
            ret += solve(e)
            visited[e] = False
    return ret


print(solve(1))
