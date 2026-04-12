from collections import defaultdict
import sys
sys.setrecursionlimit(10000)
N,M=list(map(int,input().split()))
links=defaultdict(list)
for i in range(M):
    a,b=list(map(int, input().split()))
    links[a].append(b)
    links[b].append(a)
ct=0
visited=[False]*N
def DFS(idx):
    global visited
    if all(visited):
        global ct
        ct+=1
        return
    for i in links[idx]:
        if visited[i-1]:
            continue
        visited[i-1]=True
        DFS(i)
        visited[i-1]=False
visited[0]=True
DFS(1)
print(ct)