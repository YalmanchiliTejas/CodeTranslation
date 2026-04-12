import itertools
N,M = map(int,input().split())
src = [tuple(map(int,input().split())) for i in range(M)]
es = [[] for i in range(N)]
for a,b in src:
    a,b = a-1,b-1
    es[a].append(b)
    es[b].append(a)

ans = 0
for ptn in itertools.permutations(range(1,N)):
    a = 0
    for b in ptn:
        if a not in es[b]:
            break
        a = b
    else:
        ans += 1
print(ans)