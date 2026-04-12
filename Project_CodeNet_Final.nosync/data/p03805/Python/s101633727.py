from itertools import permutations
N, M = list(map(int, input().split()))
edges = []

for i in range(M):
    a, b = list(map(int, input().split()))
    edges.append([a-1, b-1])

mat = [[0]*N for _ in range(N)]

for s, g in edges:
    mat[s][g] = 1
    mat[g][s] = 1


P = permutations(range(N))
ans = 0
for route in P:
    if route[0] != 0:
        continue
    else:
        vis = 0
        for s, g in zip(route, route[1:]):
            if mat[s][g] == 1:
                vis += 1
                if vis == N-1:
                    ans += 1
                continue
            else:
                break
print(ans)
