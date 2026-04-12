n, m = list(map(int, input().split()))
d = {}
for i in range(m):
    a, b = list(map(int, input().split()))
    a -= 1
    b -= 1
    if a not in d:
        d[a] = [b]
    else:
        d[a].append(b)
    if b not in d:
        d[b] = [a]
    else:
        d[b].append(a)

ans = 0

def DFS(now, visited):
    global ans
    if len(visited) == n:
        ans += 1
        return
    for i in d[now]:
        if i not in visited:
            DFS(i, visited + [i])

DFS(0, [0])
print(ans)