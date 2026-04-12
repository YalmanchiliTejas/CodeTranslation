import itertools as it

N,M=map(int,input().split())
e=[[False for j in range(N+1)] for i in range(N+1)]
for i in range(M):
    a,b=map(int,input().split())
    e[a][b]=e[b][a]=True
# print(e) #DB

ans=0
l=list(range(2,N+1))
for p in it.permutations(l,N-1):
    q=(1,)+p    
    # print(q) #DB
    f=True
    for i in range(N-1):
        # print((q[i],q[i+1])) #DB
        if not e[q[i]][q[i+1]]:
            f=False
            break
    if f:
        ans+=1

print(ans)