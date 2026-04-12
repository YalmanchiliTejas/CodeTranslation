def na(): return map(int, input().split())
n, m = na()
edges = [[False for _ in range(n)] for _ in range(n)]
for i in range(m):
    a, b = na()
    a -= 1
    b -= 1
    edges[a][b] = True
    edges[b][a] = True

pathes = {'0'}#permutationで求めたpath
for i in range(n-1):
    buf = set()
    for pre_path in pathes:
        for v in map(str, range(1, n)):
            if not(v in pre_path):
                buf.add(pre_path + v)
    pathes = buf.copy()
##print(pathes)
##print(edges)

ans = 0
for path in pathes:
    flg = True
    for i in range(1, n):
        a, b = map(int, [path[i-1], path[i]])
##        print(a, b, edges[a][b])
        if not edges[a][b]:
            flg = False
            break
    if flg:
        ans += 1
print(ans)