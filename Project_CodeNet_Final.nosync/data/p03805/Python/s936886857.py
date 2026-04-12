n, m = map(int, input().split())

empty = []
graphs = [[] for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a1 = a - 1
    b1 = b - 1
    graphs[a1].append(b1)
    graphs[b1].append(a1)

def dfs(v, seen):
    seen[v] = True
    if all(seen):
        return 1

    ans = 0
    for nextCandidate in graphs[v]:
        if seen[nextCandidate]:
            continue
        ret = dfs(nextCandidate, seen[:])
        ans += ret

    return ans


firstSeen = [False]*n

total = dfs(0, firstSeen)

print(total)



