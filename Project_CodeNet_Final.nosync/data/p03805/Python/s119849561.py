from itertools import permutations as perm
n,m = map(int, input().split())
edges = [[] for i in range(n)]
for i in range(m):
    a,b = map(int, input().split())
    a -= 1
    b -= 1
    edges[a].append(b)
    edges[b].append(a)

def check(l, edge):
    for i in range(1,len(l)):
        u = l[i-1]
        v = l[i]
        if v not in edges[u]:
            return False
    return True

ans = 0
for l in perm([i for i in range(n)]):
    if l[0] != 0: continue
    if check(l,edges):
        ans += 1

print(ans)