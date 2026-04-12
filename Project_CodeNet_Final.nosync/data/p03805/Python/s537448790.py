from itertools import permutations
N,M=map(int, input().split())
G=[[] for _ in range(N)]
for i in range(M):
    a,b=map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

P=list(range(2,N+1))
ans=0
for p in permutations(P):
    que=[1]+list(p)
    #print(que)
    to=que.pop(0)
    route=G[to-1]
    count=1
    while len(que)>0:
        to=que.pop(0)
        if to-1 in route:
            count+=1
            route=G[to-1]
        else:
            #print("ok")
            break
    
    if count==N:
        ans+=1
print(ans)

