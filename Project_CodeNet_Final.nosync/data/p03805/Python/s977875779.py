from collections import defaultdict


n, m = map(int, input().split())
e = [list(map(int, input().split())) for _ in range(m)]
g = defaultdict(set)

for dep, dest in e:
    g[dep].add(dest)
    g[dest].add(dep)

def dfs(i, visited=[]):
    if len(visited) == n:
        return 1
    res = 0
    for node in g[i]:
        if node not in visited:
            visited.append(node)
            res += dfs(node, visited)
            visited.pop()
    return res

ans = dfs(1, visited=[1])
print(ans)



