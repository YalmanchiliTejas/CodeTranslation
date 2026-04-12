N,M=map(int,input().split())
import itertools
graph={i:{} for i in range(1,N+1)}
for _ in range(M):
    a,b=map(int,input().split())
    graph[a][b]=1
    graph[b][a]=1
    
seq=[i+1 for i in range(N)]
Q=list(itertools.permutations(seq))
ans=0
for que in Q:
    flag=True
    s=que[0]
    if s!=1:
        flag=False
    for i in range(1,N):
        node=que[i]
        if node in graph[s]:
            s=node
        else:
            flag=False
        if flag==False:
            break
    ans+=int(flag)
print(ans)    