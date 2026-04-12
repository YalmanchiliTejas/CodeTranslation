import itertools
n, m = map(int, input().split())
G = [set() for _ in range(n)]
for _ in range(m):
    a,b = map(lambda x:int(x)-1, input().split())
    G[a].add(b)
    G[b].add(a)

P = [*itertools.permutations(range(1,n))]
ans = 0
for p in P:
    nw = 0
    for nx in p:
        if nx in G[nw]:
            nw = nx
        else:
            break
    else:
        ans += 1
print(ans)