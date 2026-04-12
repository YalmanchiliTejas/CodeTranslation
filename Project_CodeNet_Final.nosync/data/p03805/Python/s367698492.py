from copy import deepcopy
n, m, *AB = map(int, open(0).read().split())
graph = [[] for _ in range(n)]
for a, b in zip(AB[::2], AB[1::2]):
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

complete_paths = []
stack = [0]
paths = [[]]
c = 0
while stack:
    current_node = stack.pop()
    path = paths.pop()
    path.append(current_node)
    next_nodes = [n for n in graph[current_node] if n not in path]
    if next_nodes:
        for next_node in next_nodes:
            stack.append(next_node)
            paths.append(deepcopy(path))
    else:
        if len(path) == n:
            complete_paths.append(path)
print(len(complete_paths))