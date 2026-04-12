N,M = map(int, input().split())
edge= [[] for i in range(N+1)]
for i in range(M):
    a,b = map(int, input().split())
    edge[a].append(b)
    edge[b].append(a)

import itertools
per = itertools.permutations([i for i in range(1,N+1)])
ans = 0
for item in per:
    if item[0] != 1:
        continue
    f = True
    for ind,num in enumerate(item):
        if ind + 1<= N-1:
            nnum = item[ind+1]
            if nnum not in edge[num]:
                f = False

    if f:
        ans += 1

print(ans)
