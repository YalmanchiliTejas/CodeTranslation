import itertools

n,m=map(lambda x: int(x), input().split())

path={}
for i in range(n+1):
    path[i]=[]

for _ in range(m):
    a,b=map(lambda x: int(x), input().split())
    path[a].append(b)
    path[b].append(a)

node_list=list(itertools.permutations(range(2, n+1)))
ans=0
for node_tup in node_list:
    flag=True
    if node_tup[0] not in path[1]:
        continue
    for i in range(n-2):
        if node_tup[i+1] not in path[node_tup[i]]:
            flag=False
            break
    ans+=flag
print(ans)