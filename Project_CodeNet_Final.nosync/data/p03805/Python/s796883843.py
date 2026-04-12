N, M = map(int, input().split())

nodes = {}
for n in range(N):
    nodes[n] = []

for m in range(M):
    i,j = map(int, input().split())
    nodes[i-1].append(j-1)
    nodes[j-1].append(i-1)


def dfs(v):
    global reached
    global ans
    if False not in reached:
        ans += 1
        return
    for i in range(N):
        if i in nodes[v] and not reached[i]:
            reached[i] = True
            dfs(i)
            reached[i] = False
    return

ans = 0
for v in range(1):
    reached = [False for i in range(N)]
    reached[v] = True
    dfs(v)
print(ans)