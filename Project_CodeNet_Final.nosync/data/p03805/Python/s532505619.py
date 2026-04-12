from itertools import permutations

N, M = map(int, input().split())
graph = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

ans = 0
for comb in permutations(range(1, N), N-1):
    v = 0
    valid = True
    for i in comb:
        if i not in graph[v]:
            valid = False
            break
        v = i
    if valid:
        ans += 1

print(ans)
