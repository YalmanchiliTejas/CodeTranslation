import sys
sys.setrecursionlimit(10 ** 9)

def solve(cur, visited):
    if len(visited) == n:
        ans.append(1)
        return
    for i in graph[cur]:
        if not i in visited:
            solve(i, visited + [i])


n, m = map(int, input().split())
graph = [[] for i in range(n)]
ans = []

for i in range(m):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)

solve(0, [0])
print(len(ans))
