import itertools

N,M = map(int, input().split())
path = [[False] * N for x in range(N)]

for i in range(M):
    a,b = map(int, input().split())
    a,b = a-1, b-1
    path[a][b] = True
    path[b][a] = True

count = 0
for j in itertools.permutations(range(N)):
    if j[0] != 0:
        continue
    for k in range(N):
        if k == N-1:
            count += 1
            break
        if not path[j[k]][j[k+1]]:
            break
print(count)