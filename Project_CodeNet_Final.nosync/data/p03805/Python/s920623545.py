Vertex, Line = map(int, input().split())
LineList = [[int(_) for _ in input().split()] for i in range(Line)]
graph = [[] for _ in range(Vertex)]

for a, b in LineList:
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

total_one_stroke_path = 0
def search_path(now_node = 0, check_passed = 0):
    check_passed += 1 << now_node
    global total_one_stroke_path

    for next_node in graph[now_node]:
        if check_passed & (1 << next_node) == 0:
            search_path(next_node, check_passed)

    if check_passed == (1 << Vertex) - 1:
        total_one_stroke_path += 1

    return

search_path()
print(total_one_stroke_path)
exit()