def f(currentNode, visitedNodeSet):
    if len(visitedNodeSet) == N - 1:
        return 1
    sum = 0
    for a, b in AB:
        if (a == currentNode) and (b not in visitedNodeSet):
            vns = visitedNodeSet.copy()
            vns.add(a)
            sum += f(b, vns)
        if (b == currentNode) and (a not in visitedNodeSet):
            vns = visitedNodeSet.copy()
            vns.add(b)
            sum += f(a, vns)
    return sum


N, M = [int(x) for x in input().split()]
AB = []

for i in range(M):
    a, b = [int(x) for x in input().split()]
    AB.append((a, b))

# print(AB)

print(f(1, set()))
