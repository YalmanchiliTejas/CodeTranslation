N, M = map(int, input().split())
ab = [[] for _ in range(N)]

for _ in range(M):
    a, b = map(int,input().split())
    ab[a-1].append(b-1)
    ab[b-1].append(a-1)

count = 0

def dfs(i, now, done):
    global count
    if i == N-1:
        count += 1
        return

    for j in ab[now]:
        if j not in done:
            dfs(i+1, j, done + [j])
    return

dfs(0, 0, [0])
print(count)
