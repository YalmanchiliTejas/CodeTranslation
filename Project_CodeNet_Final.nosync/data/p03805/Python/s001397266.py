N,M = map(int, input().split())
edge= [[] for i in range(N+1)]
for i in range(M):
    a,b = map(int, input().split())
    edge[a].append(b)
    edge[b].append(a)

result = []

import copy
def dfs(n,used,d):
    if d == N-1:
        result.append(1)
    for e in edge[n]:
        if used[e] == False:
            usedf = copy.deepcopy(used)
            usedf[e] = True
            dfs(e,usedf,d+1)


used = [False]*(N+1)
used[1] = True
dfs(1,used,0)
print(len(result))
