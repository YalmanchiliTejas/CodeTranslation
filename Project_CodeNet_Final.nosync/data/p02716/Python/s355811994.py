N=int(input())
A=list(map(int,input().split()))
from collections import deque
q=deque([(-1,0,-2,0)])
ans=-10**18
for i,a in enumerate(A):
    d={}
    while q and q[0][0]<i:
        j,n,r,x=q.popleft()
        if r<-1:
            if n==N//2-1:
                ans=max(ans,x+a)
            elif n not in d:
                d[n]=x
            elif d[n]<x:
                d[n]=x
        if (j+1)//2<=n:
            q.append((i,n,r-1,x))
    for n,x in d.items():
        q.append((i,n+1,-1,x+a))
print(ans)