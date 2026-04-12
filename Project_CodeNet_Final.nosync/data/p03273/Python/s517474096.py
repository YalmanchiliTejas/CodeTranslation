import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

h, w = map(int, input().split())
graph = []
for _ in range(h):
    r = input().strip()
    if set(r) == {'.'}:
        continue
    graph.append(r)

transpose_graph = [[0] * len(graph) for _ in range(w)]
for i in range(len(graph)):
    for j in range(w):
        transpose_graph[j][i] = graph[i][j]

graph = []
for i in range(w):
    if set(transpose_graph[i]) == {'.'}:
        continue
    graph.append(transpose_graph[i])

transpose_graph = [[0] * len(graph) for _ in range(len(graph[0]))]
for i in range(len(graph)):
    for j in range(len(graph[0])):
        transpose_graph[j][i] = graph[i][j]

for r in transpose_graph:
    print(''.join(r))
