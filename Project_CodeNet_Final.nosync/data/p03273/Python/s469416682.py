h, w = map(int, input().split())

g = []
same = ['.'] * w
for _ in range(h):
    a = list(input())
    if a == same:
        continue
    else:
        g.append(a)

l = []
for j in range(w):
    for row in g:
        if row[j] == '#':
            break
    else:
        l.append(j)

for i in range(len(g)):
    g[i] = [g[i][j] for j in range(w) if j not in l]

for i in g:
    print(''.join(i))