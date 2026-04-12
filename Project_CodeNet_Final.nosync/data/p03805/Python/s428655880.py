n,m=map(int,input().split())
e=[[0 for _ in range(n)] for i in range(n)]
for i in range(m):
    a,s=map(int,input().split())
    e[a-1][s-1]=1;e[s-1][a-1]=1
ans=0
from itertools import permutations as pe
for i in pe(range(1,n),r=None):
    #rは長さ、Noneでiteraterの長さ
    pre=0
    for a in i:
        if e[pre][a]!=1:break
        pre=a
    else:ans+=1
print(ans)