import sys

N, M = map(int, sys.stdin.readline().rstrip().split())
edges = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    edges[a-1].append(b-1)
    edges[b-1].append(a-1)

# N, Mが十分小さいため、全探索
ans = 0
visited = set()
def dfs(s, count):
    global ans;
    # print(s, visited)
    if count == N:
       ans += 1
       return
    visited.add(s)
    for e in edges[s]:
        if e not in visited:
            dfs(e, count+1)
    visited.remove(s)

dfs(0, 1)
print(ans)