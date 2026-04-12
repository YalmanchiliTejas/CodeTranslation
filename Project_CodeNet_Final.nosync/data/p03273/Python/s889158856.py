h,w = map(int,input().split())
grid = []
datah = []
dataw = []
for i in range(h):
    l = list(input())
    grid.append(l)
    if l.count("#") == 0:
        datah.append(i)
for j in range(w):
    for k in range(h):
        if grid[k][j] == "#":
            break
    else:
        dataw.append(j)
for i in range(h):
    if i in datah:
        continue
    print("".join([grid[i][n] for n in range(w) if not n in dataw]))
