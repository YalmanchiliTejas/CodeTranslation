N=int(input())
a=list(map(int,input().split()))

data=[0 for i in range(N+1)]
ans=0
q=0
for i in range(N):
    q+=(a[i]+1)//(N+1)
    data[(a[i]+1)%(N+1)]+=1
ans=q*(N+1)

for r in range(1,N+1):
    q+=data[N+1-r]-1
    t=max(q,0)*(N+1)+r
    ans=min(ans,t)

print(ans)
