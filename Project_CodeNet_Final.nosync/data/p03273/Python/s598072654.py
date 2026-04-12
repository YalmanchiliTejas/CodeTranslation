h, w = map(int, input().split())
g = []
ans = []
for _ in range(h):
    s = [c for c in input()]
    g.append(s)
del_col = []
for j in range(w):
    col = [r[j] for r in g]
    if all([x == '.' for x in col]) :
        del_col.append(j)
del_col.sort(reverse=True)

for i in range(h):
    if not all([x == '.' for x in g[i]]):
        for d in del_col:
            g[i].pop(d)
        ans.append(g[i])
for r in ans:
    print(''.join(r))