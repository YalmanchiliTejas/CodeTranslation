N,M = map(int,input().split())
G = [[] for i in range(N+1)]
for i in range(M):
    a,b = map(int,input().split())
    G[a].append(b)
    G[b].append(a)
l = [i for i in range(2,N+1)]
import itertools
ans = 0
for v in itertools.permutations(l):
    v = list(v)
    flag = 1
    s = 1
    t = 1
    while v:
        s = t
        t = v.pop(0)
        if t not in G[s]:
            flag = 0
            break
    ans += flag
print(ans)