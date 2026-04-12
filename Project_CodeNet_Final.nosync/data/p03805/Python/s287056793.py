from collections import defaultdict

graph = defaultdict(set)
n, m = map(int, input().split())

for i in range(m):
    a, b = map(int, input().split())
    graph[a].add(b)
    graph[b].add(a)


# paths = [0] * (n+1)
# paths[1] = 1
# for i in range(1, n+1):
#     for j in graph[i]:
#         paths[j] += paths[i]
# print(paths[n])

def find_all_paths(graph, start, rest, path=[]):
    path = path + [start]
    rest2 = rest.copy()
    rest2.remove(start)
    if len(rest2) == 0:
        return [path]
    if start not in graph:
        return []
    paths = []
    for node in graph[start]:
        if node not in path:
            newpaths = find_all_paths(graph, node, rest2, path)
            for newpath in newpaths:
                paths.append(newpath)
    return paths

paths = find_all_paths(graph, 1, set(graph.keys()))
print(len(paths))