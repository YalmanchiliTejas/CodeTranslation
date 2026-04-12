N, M = map(int, input().split())
r = [[] * N for i in range(N)]
reached = [0] * N
reached[0] = 1
count = 0

def dfs(now):
    global count
    if all(reached):
        count += 1
    for next in r[now]:
        if reached[next] == 0:
            reached[next] = 1
            dfs(next)
            reached[next] = 0

for i in range(M):
    a, b = map(lambda x: int(x) - 1, input().split())
    r[a].append(b)
    r[b].append(a)

dfs(0)

print(count)
