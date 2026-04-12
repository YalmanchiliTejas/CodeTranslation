import itertools
h, w = [int(w) for w in input().split()]
field = [list(input()) for _ in range(h)]

dlist = []
nuse = [0]*w

for i in range(h):
    if not "#" in field[i]:
        dlist.append(i)
    for j in range(w):
        if field[i][j] == "#":
            nuse[j] += 1

nuse = [True if w > 0 else False for w in nuse]
for i in range(h):
    if i in dlist:
        continue
    s = list(itertools.compress(field[i], nuse))
    print("".join(s))
