def dfs(i,d,c):
    global n,f,ans
    c2=c.copy()
    c2[d]=1
    #print("#",i,d,c2)
    if i==n:
        ans+=1
        return
    for j in range(n):
        #print(d,j,c2)
        if (f[d][j]==1 or f[j][d]==1) and c2[j]==0:
            #print(d,j)
            dfs(i+1,j,c2)

n,m=map(int,input().split())
f=[[0]*n for _ in range(n)]
c1=[0]*n
ans=0
for i in range(m):
    a,b=map(int,input().split())
    a-=1
    b-=1
    f[a][b]=1
#print(f)
dfs(1,0,c1)
print(ans)