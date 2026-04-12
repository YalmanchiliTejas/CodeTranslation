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
for i in itertools.permutations(range(n),n):
    if i[0]==0:
        for j in range(n):
            if j==n-1:
                ans+=1
                break
            if not p[i[j]][i[j+1]]:
                break
print(ans)   