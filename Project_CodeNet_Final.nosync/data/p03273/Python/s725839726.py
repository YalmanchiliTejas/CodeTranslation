H, W = map(int, input().split())
graph = [list(input()) for _ in range(H)]
def rotate_cw(graph):
    height = len(graph)
    width = len(graph[0])
    result = [[] for _ in range(width)]
    for x in range(width):
        for y in range(height - 1, -1, -1):
            result[x].append(graph[y][x])
    return result

for _ in range(max(H, W)):
    for angle in range(4):
        pop = 0
        for i in range(len(graph)):
            if "#" not in graph[i-pop]:
                graph.pop(i-pop)
                pop += 1
        graph = rotate_cw(graph)
for line in graph:
    print("".join(line))