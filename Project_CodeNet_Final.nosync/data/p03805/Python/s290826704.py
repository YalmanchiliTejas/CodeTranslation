N, M = list(map(int, input().split()))

ans = 0

def dfs(n, visited):
    global ans
    visited.append(n)
    if len(visited) == N:
        ans += 1
    else:
        for i in l[n-1]:
            if i not in visited:
                dfs(i, visited)
    visited.remove(n)

l = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    l[a-1].append(b)
    l[b-1].append(a) 

dfs(1, [])
print(ans)