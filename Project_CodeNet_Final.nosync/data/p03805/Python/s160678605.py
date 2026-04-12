import itertools
n, m = map(int, input().split())

edges = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    edges[a - 1].append(b - 1)
    edges[b - 1].append(a - 1)
cnt = 0
for path in itertools.permutations(range(1, n)):
    # 0はじまり
    path = [0] + list(path)
    flg = True
    for i in range(1, n):
        if path[i] not in edges[path[i-1]]:
            flg = False
            break
    if flg:
        cnt += 1

print(cnt)