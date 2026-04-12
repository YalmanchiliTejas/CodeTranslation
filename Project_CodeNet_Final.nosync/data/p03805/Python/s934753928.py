import itertools

n,m = map(int,input().split())
E = [list(map(int,input().split())) for i in range(m)]
G = [[] for i in range(n)]
for i in range(m):
    G[E[i][0]-1] += [E[i][1]-1]
    G[E[i][1]-1] += [E[i][0]-1]

ans = 0
for p in itertools.permutations(range(1,n)):
    if p[0] in G[0] and all([p[i] in G[p[i-1]] for i in range(1,n-1)]):
        ans += 1

print(ans)