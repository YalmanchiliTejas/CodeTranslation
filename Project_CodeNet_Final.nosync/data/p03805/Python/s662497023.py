N, M = map(int, input().split())
ab = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    ab[a-1].append(b-1)
    ab[b-1].append(a-1)

ans = 0
def dfs(x, visited):
    global ans
    if len(visited) == N:
        ans += 1
        return

    for b in ab[x]:
        if b not in visited:
            dfs(b, visited + [b])
    return

dfs(0, [0])
print(ans)
