N, M = list(map(int, input().split()))
AB = []
for i in range(M):
    a, b = list(map(int, input().split()))
    AB.append([a, b])

graph = []
for i in range(N):
    graph.append([False]*N)

for a, b in AB:
    a -= 1
    b -= 1
    graph[a][b] = True
    graph[b][a] = True

# for gi in graph:
#     print(gi)

from itertools import permutations
l = [i for i in range(1, N)]
patterns = list(permutations(l))

# print(patterns)

cnt = 0
for pi in patterns:
    cur = 0
    ok = True
    # t: 次の目的地
    for t in pi:
        if not graph[cur][t]:
            ok = False
        cur = t
    if ok:
        cnt += 1


print(cnt)
