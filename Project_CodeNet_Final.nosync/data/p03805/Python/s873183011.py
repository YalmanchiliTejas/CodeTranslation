# coding: utf-8
# Your code here!
import itertools
N,M=map(int,input().split())
path=[[False]*N for _ in range(N)]
for i in range(M):
    a,b=[int(j) for j in input().split()]
    path[a-1][b-1]=True
    path[b-1][a-1]=True
ans=0
for junjo in itertools.permutations(range(1,N)):
    nexts=list(junjo)
    if path[0][nexts[0]]==False:continue
    if all([path[nexts[i]][nexts[i+1]] for i in range(N-2)]):
        ans+=1
print(ans)