from itertools import permutations

N, M = map(int,input().split())
edges = [[0 for i in range(N)] for j in range(N)]
for _ in range(M):
    a, b = map(int,input().split())
    edges[a-1][b-1] = 1
    edges[b-1][a-1] = 1

ans = 0
for l in permutations(range(1,N)):
    l = [0] + list(l)
    cnt = 1
    for i in range(N-1):
        if edges[l[i]][l[i+1]] == 0:
            cnt = 0
    ans += cnt

print(ans)