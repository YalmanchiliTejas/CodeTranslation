H, W = map(int, input().split())
graph = [list(input()) for _ in range(H)]
flg = True
while flg:
    loop = False
    for i in range(len(graph)):
        if "#" not in graph[i]:
            graph.pop(i)
            loop = True
            break
    if loop:
        continue
    for j in range(len(graph[0])):
        tate = [line[j] for line in graph]
        if "#" not in tate:
            for i in range(len(graph)):
                graph[i].pop(j)
            break
    else:
        flg = False
for line in graph:
    print("".join(line))
