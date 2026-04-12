N, M = map(int,input().split())
edges = [[] for _ in range(N)]
for _ in range(M):
    a,b = map(int,input().split())
    edges[a-1].append(b-1)
    edges[b-1].append(a-1)

def dfs(i, used):
    if len(used) == N:
        return 1
    ans = 0
    for j in edges[i]:
        if j not in used:
            ans += dfs(j, used+[j])
    return ans
print(dfs(0, [0]))