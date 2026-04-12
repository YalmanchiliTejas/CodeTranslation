import copy
from collections import deque
cnt = 0
def dfs(G,s,n,seen):
    global cnt
    li = copy.copy(seen)
    li.append(s)
    if len(li) == n:
        cnt += 1
        return 0
    for x in G[s]:
        if x in li:
            continue
        dfs(G,x,n,li)

N,m = map(int,input().split())
seen = []
G = [[] for _ in range(N)]
for i in range(m):
    a,b = map(lambda x:int(x)-1,input().split())
    G[a].append(b)
    G[b].append(a)
dfs(G,0,N,seen)
print(cnt)