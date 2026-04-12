import itertools
N,M = map(int,input().split())
src = [tuple(map(lambda x:int(x)-1,input().split())) for i in range(M)]

es = [set() for i in range(N)]
for a,b in src:
    es[a].add(b)
    es[b].add(a)

ans = 0
for ptn in itertools.permutations(range(1,N)):
    v = 0
    for to in ptn:
        if to not in es[v]:
            break
        else:
            v = to
    else:
        ans += 1
print(ans)