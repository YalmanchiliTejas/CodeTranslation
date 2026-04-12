H, W = map(int, input().split())
g = []
cols = set()
for _ in range(H):
    r = input()
    if r != "." * W:
        g.append(r)
        for i in range(W):
            if r[i] == "#":
                cols.add(i)
cols = sorted(cols)
for r in g:
    print(*[r[i] for i in cols], sep="")