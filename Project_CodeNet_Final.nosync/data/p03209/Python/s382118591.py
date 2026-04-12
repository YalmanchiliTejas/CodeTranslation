n,x=map(int,input().split())
p=[0]*51
b=[0]*51
p[0]=1
for i in range(50):
    p[i+1]=2*p[i]+1
    b[i+1]=2*b[i]+2
def dfs(n,x):
    if x<=n:
        return 0
    if n==0:
        return 1
    z=p[n]+b[n]
    if z//2==x:
        return p[n-1]
    elif z//2+1==x:
        return p[n-1]+1
    elif z//2+1<x:
        return p[n-1]+1+dfs(n-1,x-z//2-1)
    else:
        return dfs(n-1,x-1)
print(dfs(n,x))
