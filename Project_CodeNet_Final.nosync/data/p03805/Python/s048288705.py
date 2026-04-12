n,m = map(int, input().split())
edge = [[] for _ in range(n)]
for i in range(m):
    a,b = map(int, input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)
#print(edge)

import itertools
l = []
for i in range(1,n):
    l.append(i)
llist = list(itertools.permutations(l))
#print(llist)

ans = 0
for i in range(len(llist)):
    x = [0] + list(llist[i])
    tnp = 0
    for j in range(n-1):
        if not x[j+1] in edge[x[j]]:
            tnp += 1
            break
    if (tnp==0):
        ans += 1
print(ans)
            