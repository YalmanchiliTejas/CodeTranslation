import copy
def explore(key, flags):
    flags = copy.copy(flags)
    if flags[key-1]:
        return 0
    flags[key-1] = True
    if False not in flags:
        return 1
    elif key in graph:
        value = graph[key]
        ans = 0
        for i in value:
            ans += explore(i, flags)
        return ans
    else:
        return 0

n, m = map(int, input().split())
graph = {}
for i in range(m):
    a, b = map(int, input().split())
    if a in graph:
        graph[a].append(b)
    else:
        graph[a] = [b]
    if b in graph:
        graph[b].append(a)
    else:
        graph[b] = [a]

flags = [False for i in range(n)]
ans = explore(1, flags)
print(ans)
