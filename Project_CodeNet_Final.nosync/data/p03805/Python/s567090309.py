def ary(r, c, v): return [[v for _ in range(c)] for _ in range(r)]
n, m = map(int, input().split())
e = ary(n, n, False)
for i in range(m):
    a, b = map(int, input().split())
    #頂点を0-indexedに変換
    a -= 1
    b -= 1
    e[a][b] = True
    e[b][a] = True
ps = set()
ps.add('0')

for cnt in range(1, n):
    t = set()
    for p in ps:
        for i in map(str, range(1, n)):
            if not(i in p):
                t.add(p + i)
    ps = t.copy()

ans = 0
for p in ps:
    flg = True
    for i in range(n - 1):
        a = int(p[i])
        b = int(p[i + 1])
        if not e[a][b]:
            flg = False
            break
    if flg:
        ans += 1

print(ans)