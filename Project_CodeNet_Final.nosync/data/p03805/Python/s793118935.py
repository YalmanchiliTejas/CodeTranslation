n, m = map(int, input().split())
ab = [list(map(int, input().split())) for x in range(m)]

abmap = {}
for a, b in ab:
    atarget = abmap.get(a)
    if atarget == None:
        abmap[a] = []
    abmap[a].append(b)

    btarget = abmap.get(b)
    if btarget == None:
        abmap[b] = []
    abmap[b].append(a)

que = [[1, abmap[1], []]]
ends = []
while que:
    now, nextnodes, visited = que.pop()
    ends.append(visited)
    visited.append(now)
    for node in nextnodes:
        if node in visited:
            continue
        mvisited = visited[:]
        que.append([node, abmap[node], mvisited])

print(len(list(filter(lambda x: len(x) == n, ends))))
