from itertools import permutations
n,m = map(int,input().split())
G = [[] for _ in range(n)]
for _ in range(m):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)
ans = 0
for p in permutations(range(1,n)):
    now = 0
    for nxt in p:
        if nxt not in G[now]: break
        now = nxt
    else:
        ans += 1
print(ans)