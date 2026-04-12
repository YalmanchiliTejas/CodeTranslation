h, w = map(int, input().split())

g = []
for i in range(h):
    g.append(input())

g2 = []
for line in g:
    if '#' in line:
        g2.append(line)

g3 = []
for _ in g2: g3.append([])

for j in range(w):
    if any([g2[i][j] == '#' for i in range(len(g3))]):
        for i in range(len(g3)):
            g3[i].append(g2[i][j])

for line in g3:
    print(''.join(line))