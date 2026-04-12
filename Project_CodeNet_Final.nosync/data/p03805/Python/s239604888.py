N, M = map(int, input().split())
l = [[] for _ in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    l[a - 1].append(b - 1)
    l[b - 1].append(a - 1)

ans = 0


# pos:現在地 visit:巡回済み頂点のリスト
def dfs(pos, visit):
    global l, ans
    f = True
    visit.append(pos)
    for d in l[pos]:
        if (d in visit):
            continue
        f = False
        dfs(d, visit.copy())

    if (f):
        if (len(visit) == N):
            ans += 1


dfs(0, [])
print(ans)
