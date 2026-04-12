import itertools
N,M = map(int,input().split())
es = [[0 for j in range(N)] for i in range(N)]
for i in range(M):
    a,b = map(int,input().split())
    a,b = a-1,b-1
    es[a][b] = es[b][a] = 1

ans = 0
for ptn in itertools.permutations(range(1,N)):
    prev = 0
    for v in ptn:
        if not es[prev][v]:
            break
        prev = v
    else:
        ans += 1
print(ans)