n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)


def dfs(root):
    now = root[-1]
    ret = []
    for i in graph[now]:
        if i in root:
            pass
        else:
            ret.append(dfs(root + [i]))
    if not ret:
        if len(root) == n:
            return 1
        return 0

    return sum(ret)


print(dfs([1]))
