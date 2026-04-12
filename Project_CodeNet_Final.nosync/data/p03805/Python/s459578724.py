from itertools import *

N, M = map(int, input().split())
G = [set() for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    G[a-1].add(b-1)
    G[b-1].add(a-1)

ans = 0

for p in permutations(range(N)):
    if p[0]!=0:
        continue
    
    flag = True
    
    for i in range(N-1):
        if p[i+1] not in G[p[i]]:
            flag = False
    
    if flag:
        ans += 1

print(ans)