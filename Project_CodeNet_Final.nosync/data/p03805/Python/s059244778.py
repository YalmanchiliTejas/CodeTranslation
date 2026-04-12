def find_route(now, node, route):
    count = 0
    if min(node) == 1:
        return 1
    dist = route[now]
    for i in dist:
        if node[i] == 0:
            tmpnode = node.copy()
            tmpnode[i] = 1
            count += find_route(i, tmpnode, route)
    return count

(n, m) = list(map(int, input().split()))
route = {}
for i in range(m):
    (a, b) = list(map(int, input().split()))
    a -= 1
    b -= 1
    if a in route:
        route[a].append(b)
    else:
        route[a] = [b]
    if b in route:
        route[b].append(a)
    else:
        route[b] = [a]
count = find_route(0, [1] + [0 for _ in range(n - 1)], route)

print(count)