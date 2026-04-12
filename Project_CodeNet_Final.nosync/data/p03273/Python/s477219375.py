h, w = map(int, input().split())
p = [input() for i in range(h)]

r = set()
c = set()

for i in range(h):
    for j in range(w):
        if p[i][j] == '#':
            r.add(i)
            c.add(j)

for i in range(h):
    for j in range(w):
        if i in r and j in c:
            print(p[i][j], end='')
    if i in r:
        print()
