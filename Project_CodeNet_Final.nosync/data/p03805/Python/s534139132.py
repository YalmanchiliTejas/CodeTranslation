N,M=map(int,input().split())
G=[[] for _ in range(N)]

for i in range(M):
    a,b=map(int,input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

seen=[0]*N
ans=[]

def DFS(x,n):
    if len(n)==N:
        return True
    for a in G[x]:
        if seen[a]==0:
            seen[a]=1
            if DFS(a,n+str(a)):ans.append(n+str(a))
            seen[a]=0
seen[0]=1
DFS(0,"0")

print(len(ans))


