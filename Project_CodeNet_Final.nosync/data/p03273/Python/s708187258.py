a, b = map(int, input().split())
c = [True] * a
d = [True] * b
f = []
for i in range(a):
    e = input()
    g = []
    for j in range(b):
        g.append(e[j])
        if e[j] == "#":
            if c[i]:
                c[i] = not c[i]
            if d[j]:
                d[j] = not d[j]
    f.append(g)
for i in range(len(c)):
    if not c[i]:
        h = ""
        for j in range(len(d)):
            if not d[j]:
                h += f[i][j]
        print(h)
