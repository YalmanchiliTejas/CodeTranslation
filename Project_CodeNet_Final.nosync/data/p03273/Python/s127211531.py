a, b = map(int, input().split())
e = []
f = [True] * b
for i in range(a):
    c = list(input())
    d = True
    for j in range(b):
        if c[j] == "#" and d:
            d = not d
        if c[j] == "#" and f[j]:
            f[j] = not f[j]
    if not d:
        e.append(c)
for i in range(len(e)):
    g = ""
    for j in range(b):
        if not f[j]:
            g += e[i][j]
    print(g)
