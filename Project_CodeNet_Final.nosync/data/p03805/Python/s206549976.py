import itertools

N, M = map(int, input().split())
transit = [[0]*N for _ in range(N)]

for m in range(M):
    a, b = map(int, input().split())
    transit[a-1][b-1] = 1
    transit[b-1][a-1] = 1
permutation = list(itertools.permutations(list(range(1, N+1))))
ans = 0
for p in permutation:
    if p[0] != 1:
        continue
    for i in range(len(p) - 1):
        if transit[p[i]-1][p[i+1]-1] != 1:
            break
        if i == len(p) - 2:
            ans += 1
print(ans)
