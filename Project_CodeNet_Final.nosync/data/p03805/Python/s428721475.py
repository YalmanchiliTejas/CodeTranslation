N, M = map(int, input().split())

edges = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    edges[a - 1].append(b - 1)
    edges[b - 1].append(a - 1)


def dfs(node, track):
    if len(track) == N:
        global res
        res += 1
    else:
        for dst in [x for x in edges[node] if x not in track]:
            dfs(dst, track + tuple([dst]))


res = 0
dfs(0, tuple([0]))
print(res)
