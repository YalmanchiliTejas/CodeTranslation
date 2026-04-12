from collections import deque

n, m = list(map(int, input().split()))
li = []
for _ in range(m):
    li.append(list(map(int, input().split())))

# construct indirected graph
edges = [[] for _ in range(n)]
for i, j in li:
    edges[i - 1].append(j - 1)
    edges[j - 1].append(i - 1)

ans = 0
S = deque()
S.append([0])
while len(S) > 0:
    path = S.pop()
    for v in edges[path[-1]]:
        if v not in path:
            if len(path) + 1 == n:
                ans += 1
            else:
                S.append(path + [v])


print(ans)