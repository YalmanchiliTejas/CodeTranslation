from itertools import permutations

N, M = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(M)]

graph = [[] for _ in range(N)]

for a, b in ab:
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)

perm = [i for i in range(N)]

ans = 0

for p in permutations(perm):
    # 1開始でないならNG（辞書順なのでbreakでOK）
    if p[0] != 0:
        break
    flag = False
    for i in range(len(p) - 1):
        if not p[i + 1] in graph[p[i]]:
            flag = True
            break

    if not flag:
        # print(p)
        ans += 1

print(ans)
