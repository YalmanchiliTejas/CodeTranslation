N,M=map(int,input().split())
L=[[] for _ in range(N)]
visited=[True]+[False]*(N-1)
for _ in range(M):
    a,b=map(int,input().split())
    L[a-1].append(b-1)
    L[b-1].append(a-1)
def dfs(now,cnt):
    ans=0
    if cnt==N:
        return 1
    for nxt in L[now]:
        if visited[nxt]:
            continue
        visited[nxt]=True
        ans+=dfs(nxt,cnt+1)
        visited[nxt]=False
    return ans
print(dfs(0,1))