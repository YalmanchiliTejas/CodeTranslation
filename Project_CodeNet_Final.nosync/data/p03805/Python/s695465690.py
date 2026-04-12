from itertools import permutations
n,m=map(int,input().split())
graph=[[] for i in range(n+1)]
for i in range(m):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

    
ans=0

for i in permutations(range(1,n+1)):
    if i[0]!=1:
        continue
    for j in range(n-1):
        if i[j+1] not in graph[i[j]]:
            break
    else:
        ans+=1
print(ans)