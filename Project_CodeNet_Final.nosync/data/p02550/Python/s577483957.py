n,x,m=map(int,input().split())
seen=[-1]*(2*10**5)
A=[0]*(2*10**5)
A[0]=x


now=x ;seen[x]=0
for i in range(1,n):
    now= (now**2)%m 
    A[i]=now
    if seen[now]!=-1:
        st = sum(A[:seen[now]])
        gr = sum(A[seen[now]: i ])
        naga= i-seen[now]
        ret = (n-seen[now])//naga
        print(st+ gr*ret + sum(A[seen[now]: seen[now]+(n-seen[now])%naga]))
        exit()
    else:
        seen[now]=i
else:
    print(sum(A[:n]))