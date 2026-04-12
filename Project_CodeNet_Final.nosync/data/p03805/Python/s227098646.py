import itertools
n,m=map(int,input().split())
p=[[False]*n for i in range(n)]

for i in range(m):
    a,b=map(int,input().split())
    a-=1
    b-=1
    p[a][b]=True
    p[b][a]=True
ans=0
for i in itertools.permutations(range(1,n),n-1):
    list=[0]+[k for k in i]
    if all(p[list[j]][list[j+1]]==True for j in range(n-1)):
        ans+=1
print(ans)   
