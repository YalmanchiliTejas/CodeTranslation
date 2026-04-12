N, M = map(int, input().split())
edge = [[] for _ in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)

seen = [False] * N

def dfs(node, seen, ans):
    seen[node] = True
    #print(node)
    if seen.count(True) == N:
        ans += 1
        seen[node] = False
        return ans

    for todo in edge[node]:
        if not seen[todo]:
            ans = dfs(todo, seen, ans)

    seen[node] = False
    return ans

print(dfs(0, seen, 0))