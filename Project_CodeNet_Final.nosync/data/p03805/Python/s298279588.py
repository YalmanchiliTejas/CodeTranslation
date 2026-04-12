#n=int(input())
n,m=map(int,input().split())
#l=list(map(int,input().split()))
#l=[list(map(int,input().split())) for i in range(n)]

adjl=[[0 for i in range(n)] for j in range(n)]

for i in range(m):
    a,b=map(int,input().split())
    adjl[a-1][b-1]=1
    adjl[b-1][a-1]=1

import itertools
l=[i for i in range(1,n+1)]
ans=0
#p = itertools.permutations(l)
for v in itertools.permutations(l):
    #tupleで返ってくる
    #print(v[0])
    flag=True
    if v[0]!=1 :
        continue
    for i in range(n-1):
        if adjl[v[i]-1][v[i+1]-1]==0:
            flag=False
            break
    if flag:
        ans+=1
print(ans)
