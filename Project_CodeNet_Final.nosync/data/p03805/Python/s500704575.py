N, M = map(int, input().split())
E = {i: [] for i in range(1, N+1)}
for _ in range(M):
    a, b = map(int, input().split())
    E[a].append(b)
    E[b].append(a)

def res(a, i, E, visit):
    global cnt
    if i == N:
        cnt += 1
        return None
    if E[a]:
        for b in E[a]:
            if b in visit:
                pass
            else:
                res(b, i+1, E, visit + [a])
        return None
    else:
        return None

cnt = 0
res(1, 1, E, [])
print(cnt)