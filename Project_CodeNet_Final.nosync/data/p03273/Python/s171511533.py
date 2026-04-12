h, w = map(int, input().split())
g = []
for i in range(h):
    g.append(input())
flg = [[0] * w for _ in range(h)]

for i in range(h):
    if all(c == "." for c in g[i]):
        for j in range(w):
            flg[i][j] = 1

for j in range(w):
    if all(d[j] == "." for d in g):
        for i in range(h):
            flg[i][j] = 1

res = []
for i in range(h):
    su = ""
    for j in range(w):
        if not flg[i][j]:
            su += g[i][j]
    if su:
        res.append(su)
print(*res, sep="\n")
