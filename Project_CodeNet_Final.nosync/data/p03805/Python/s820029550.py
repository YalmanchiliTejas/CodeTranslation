def dfs(parent, connect, passed, N):
    cnt = 0
    passed.append(parent)
    if len(passed) == N:
        cnt = 1
    for next_ in connect[parent]:
        if next_ in passed:
            continue
        cnt += dfs(next_, connect, passed, N)
    passed.pop()
    return cnt    

N, M = map(int, input().split())
connect = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    connect[a-1].append(b-1)
    connect[b-1].append(a-1)
ans = dfs(0, connect, [], N)
print(ans)