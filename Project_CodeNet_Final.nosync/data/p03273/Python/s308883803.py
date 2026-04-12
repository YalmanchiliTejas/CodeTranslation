h, w = map(int, input().split())
a = []
c = 0
for i in range(h):
    b = list(input())
    if "#" in b:
        a.append(b)
        c += 1
d = []
for i in range(w):
    e = []
    for j in range(c):
        e.append(a[j][i])
    else:
        d.append(e)
f = []
g = 0
for i in range(w):
    if "#" in d[i]:
        f.append(d[i])
        g += 1
h = []
for i in range(c):
    e = []
    for j in range(g):
        e.append(f[j][i])
    else:
        h.append(e)
for i in range(c):
    print(*h[i], sep="")