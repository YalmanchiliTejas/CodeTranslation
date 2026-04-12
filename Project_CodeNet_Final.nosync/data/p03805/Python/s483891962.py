from collections import defaultdict,deque
import itertools

N, M = map(int, input().split())
d = defaultdict(list)
for i in range(M):
    a, b = map(int, input().split())
    d[a].append(b)
    d[b].append(a)

p=list(itertools.permutations([i for i in range(2,N+1)]))
now=1
ans=0
for i in p:
    now=1
    frag=True
    for g in range(N-1):
        if i[g] in d[now]:
            now = i[g]
        else:
            frag=False
            break
    if frag:
        ans+=1
print(ans)