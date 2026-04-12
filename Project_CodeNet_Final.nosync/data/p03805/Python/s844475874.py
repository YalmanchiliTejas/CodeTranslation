import itertools
N,M = map(int,input().split())
edges = {tuple(map(int,input().split())) for i in range(M)}
ans = 0
for i in itertools.permutations(range(2,N+1),N-1):
    l = [1]+list(i)
    ans += all(tuple(sorted(edge)) in edges for edge in zip(l,l[1:]))
print(ans)