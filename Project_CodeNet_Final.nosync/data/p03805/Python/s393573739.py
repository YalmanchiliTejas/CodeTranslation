
from itertools import permutations

n,m=map(int,input().split())
ans=0
s=[list(map(int,input().split())) for i in range(m)]

t=list(permutations(list(range(1,n+1))))
for i in range(len(t)):
    flag=True
    if t[i][0]!=1: continue
    for j in range(n-1):
        a=sorted([t[i][j],t[i][j+1]])
        if a not in s: flag=False
    if flag: ans+=1
print(ans)