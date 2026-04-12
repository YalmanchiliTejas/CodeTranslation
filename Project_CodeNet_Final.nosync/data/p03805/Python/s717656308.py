import itertools
n,m=map(int,input().split())
path=[]
for i in range(m):
    a,b=map(int,input().split())
    path.append([a,b])
    path.append([b,a])
ans=0
factorial=list(itertools.permutations(list(range(1,n+1))))

for i in range(len(factorial)):
    if factorial[i][0]!=1:
        continue
    flag=True
    for j in range(1,n):
        if [factorial[i][j-1],factorial[i][j]] not in path:
            flag=False
    ans+=flag
print(ans)