import copy

N, M = input().split()
N = int(N)
M = int(M)

abList = []
for i in range(M):
    a,b = input().split()
    a = int(a)
    b = int(b)
    abList.append((a,b))


def dfs(graph, now, done):
    result = 0
    doneCache = copy.deepcopy(done)
    doneCache.append(now)
    if len(doneCache) == N:
        return 1
    for a,b in graph:
        if a == now:
            if b not in doneCache:
                result += dfs(graph, b, doneCache)
        if b == now:
            if a not in doneCache:
                result += dfs(graph, a, doneCache)

    return result

print(dfs(abList, 1, []))