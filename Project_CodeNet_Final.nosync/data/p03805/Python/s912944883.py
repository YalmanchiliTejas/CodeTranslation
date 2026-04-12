import sys
sys.setrecursionlimit(10**7)
import copy
N,M=map(int,input().split())
G=[[]for _ in range(N)]

for i in range(M):
    a,b=map(int,input().split())
    a-=1
    b-=1
    G[a].append(b)
    G[b].append(a)

ans=0
def bfs(v,chk,G):
    global ans
    #print(chk)
    if chk[v]!=0:
        return
    chk[v]=1
    if sum(chk)==N:
        ans+=1
    for tmp in G[v]:
        chk1=copy.copy(chk)
        bfs(tmp,chk1,G)

chk=[0]*N
bfs(0,chk,G)
print(ans)